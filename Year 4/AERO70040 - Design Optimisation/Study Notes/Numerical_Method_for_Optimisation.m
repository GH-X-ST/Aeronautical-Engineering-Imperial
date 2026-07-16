%% Housekeeping
clear
clc

%% Test


%% Exact Line Search

% 5.1 - Bracketing a Minimum
function [a, b, c] = bracket_min(f, x0, step, grow, maxit)

% input:
% f     - objective function
% x0    - initial guess
% step  - initial step size
% grow  - step growth rate
% maxit - maximum iterations

% output:
% a     - bracket min
% b     - a < b < c
% c     - bracket max

% initialisation
a = x0;
b = a + step;

% check descent direction
if f(a) < f(b)
    step = -step;
    b = a + step;
    % check whether initial guess is low resolution min
    if f(a) < f(b)
        b = a;
        a = b - abs(step);
        c = b + abs(step);
        return
    end
end

% scale to bracket
c = b + step;
k = 0;
while (f(c) < f(b)) && (k < maxit)
    k = k + 1;
    step = grow * step;
    a = b;
    b = c;
    c = b + step;
    if k == maxit
        warning('unsolved, reach maximum iteration')
    end
end

% check orientation
if c < a
    d = a;
    a = c;
    c = d;
end

% end function
end


% 5.2 -  Golden-Section Search
function [xmin, xhist, fhist] = golden_search(f, x0, tol, maxit)

% input:
% f     - objective functions
% x0    - initial guess
% tol   - tolerance
% maxit - maximum iterations

% output:
% xmin  - local min
% xhist - search history for x
% fhist - search history for f(x)

% bracket the minimum first
[a, ~, b] = bracket_min(f, x0, 0.1, 5, 50);

% initialisation
xmin = 0.5 * (a + b);
xhist = zeros(maxit, 1);
fhist = zeros(maxit, 1);
phi = 0.618;
k = 0;

% first step
x1 = a + (1 - phi) * (b - a);
f1 = f(x1);
x2 = a + phi * (b - a);
f2 = f(x2);

% golden search
while (abs(b - a) > tol) && (k < maxit)
    k = k + 1;
    % reduce interval
    if f1 > f2
        % reuse
        a = x1;
        x1 = x2;
        f1 = f2;
        % calculate
        x2 = a + phi * (b - a);
        f2 = f(x2);
    else
        % reuse
        b = x2;
        x2 = x1;
        f2 = f1;
        % calculate
        x1 = a + (1 - phi) * (b - a);
        f1 = f(x1);
    end
    % compute result for current step
    xmin = 0.5 * (a + b);
    xhist(k) = xmin;
    fhist(k) = f(xmin);
    if k == maxit
        warning('unsolved, reach maximum iteration')
    end
end

% cut the history array to suitable length
xhist = xhist(1 : k);
fhist = fhist(1 : k);

% end function
end

%% Inexact Line Search

% 6.1.2 Armijo Condition and Backtracking Line Search
function [a, ahist] = Armijo(f, df, xk, pk, beta, c1, maxit)

% input:
% f     - f(x)
% df    - df(x)
% xk    - x_k
% pk    - p(x_k)
% beta  - shrinkage factor
% c1    - scaling factor
% maxit - maximum iterations

% output:
% a     - step size
% ahist - searching history

% initialisation
k = 0;
a = 1.0;
ahist = zeros(maxit, 1);

fxk = f(xk);
dfxk = df(xk);

fa = @(a) f(xk + a * pk);

% check descent direction
if dfxk.' * pk >= 0
    warning('p_k is not descent direction');
end

% Armijo line search
while k < maxit
    k = k + 1;
    ahist(k) = a;
    % check Armijo
    if fa(a) <= fxk + c1 * a * (dfxk.' * pk)
        break
    else
        a = a * beta;
    end
    % check iteration
    if k == maxit
        warning('Armijo reach the maximum iteration before find step size')
    end
end

% keep useful history only
ahist = ahist(1 : k);

% end function
end


% 6.1.3 Wolfe Conditions for Inexact Line Search
function [a, ahist] = Wolfe(f, df, xk, pk, c1, c2, maxit)

% input:
% f     - f(x)
% df    - f'(x)
% xk    - x_k
% pk    - p(x_k)
% c1    - scaling factor for Armijo
% c2    - scaling factor for Wolfe
% maxit - maximum iterations

% output:
% a     - step size
% ahist - search history

% initialisation
k = 0;
a = 1.0;

fxk = f(xk);
dfxk = df(xk);

fa = @(a) f(xk + a * pk);
dfa = @(a) df(xk + a * pk);

ahist = zeros(maxit, 1);

alow = 0;
ahigh = 0;

% check descent direction
if dfxk.' * pk >= 0
    warning('p_k is not a descent direction, Wolfe may fail')
end

% bisection method
while k < maxit
    k = k + 1;
    ahist(k) = a;

    % check Armijo
    if fa(a) <= fxk + c1 * a * (dfxk.' * pk)

        % check Wolfe
        if abs(dfa(a).' * pk) <= c2 * abs(dfxk.' * pk)
            break
        else

            % check gradient
            if dfa(a).' * pk > 0
                ahigh = a;
                a = 0.5 * (alow + ahigh);
            else
                alow = a;
                % check whether upper bound is defined
                if ahigh == 0
                    a = 2 * a;
                else
                    a = 0.5 * (alow + ahigh);
                end

            end

        end

    else
        ahigh = a;
        a = 0.5 * (alow + ahigh);
    end

    % check iteration
    if k == maxit
        warning('Wolfe reach max iteration before solve')
    end
end

% shrink history
ahist = ahist(1 : k);

% end function
end

%% Unconstraint Optimisation

% 6.2 Gradient Descent (Steepest Descent) Method
function [xmin, xhist, ahist, fhist] = gradient_descent(f, df, x0, tol, maxit)

% input:
% f     - f(x)
% df    - f'(x)
% x0    - initial guess
% tol   - tolerance
% maxit - maximum iterations

% output:
% xmin  - local minimiser
% xhist - search history
% ahist - line search history
% fhist - function value history

% initialisation
k = 0;
x = x0;

xhist = zeros(maxit, length(x0));
ahist = zeros(maxit, 1);
fhist = zeros(maxit, 1);

% gradient descent
while (norm(df(x)) > tol) && (k < maxit)
    k = k + 1;

    % descent direction
    p = -df(x);

    % exact line search
    % fa = @(a) f(x + a * p);
    % [a, ~, ~] = golden_search(fa, a, 1e-3, 300);

    % Armijo
    [a, ~] = Armijo(f, df, x, p, 0.5, 1e-4, 300);

    % Wolfe
    % [a, ~] = Wolfe(f, df, x, p, 1e-4, 0.9, 300);

    % update
    xhist(k, :) = x;
    ahist(k) = a;
    fhist(k) = f(x);

    % x_(k+1)
    x = x + a * p;

    % check iteration
    if k == maxit
        warning('gradient method reach maximum iteration before yield solution')
    end

end

% shrink the history
xhist = xhist(1: k, :);
ahist = ahist(1: k);
fhist = fhist(1: k);

% final output
xmin = x;

% end function
end


% 6.3 Newton's Method
function [xmin, xhist, ahist, fhist] = Newton_method(f, df, ddf, x0, tol, maxit)

% input:
% f     - f(x)
% df    - f'(x)
% ddf   - f''(x)
% x0    - initial guess
% tol   - tolerance
% maxit - maximum iterations

% output:
% xmin  - local minimiser
% xhist - search history
% ahist - line search history
% fhist - function value history

% initialisation
k = 0;
x = x0;

xhist = zeros(maxit, length(x0));
ahist = zeros(maxit, 1);
fhist = zeros(maxit, 1);

% Newton's method
while (norm(df(x)) > tol) && (k < maxit)

    k = k + 1;

    % descent direction
    p = -ddf(x) \ df(x);

    % safe guard
    if p >= 0
        p = -df(x);
    end

    % line search

    % classic Newton
    a = 1.0;

    % exact line search
    % fa = @(a) f(x + a * p);
    % [a, ~, ~] = golden_search(fa, a, 1e-3, 300);

    % Armijo
    % [a, ~] = Armijo(f, df, x, p, 0.5, 1e-4, 300);

    % Wolfe
    % [a, ~] = Wolfe(f, df, x, p, 1e-4, 0.9, 300);

    % assign value
    xhist(k, :) = x;
    ahist(k) = a;
    fhist(k) = f(x);

    % x_(k+1)
    x = x + a * p;

    % check iteration
    if k == maxit
        warning('Newton method reach maximum iteration before solve')
    end

end

% shrink history
xhist = xhist(1 : k, :);
ahist = ahist(1 : k);
fhist = fhist(1 : k);

% final output
xmin = x;

% end function
end


% 6.4 Quasi-Newton Method
function [xmin, xhist, ahist, fhist] = DFP_method(f, df, x0, tol, maxit)

% input:
% f     - f(x)
% df    - f'(x)
% x0    - initial guess
% tol   - tolerance
% maxit - maximum iterations

% output:
% xmin  - local minimiser
% xhist - search history
% ahist - line search history
% fhist - function value history

% initialisation
k = 0;
x = x0;
B = eye(length(x0));

xhist = zeros(maxit, length(x0));
ahist = zeros(maxit, 1);
fhist = zeros(maxit, 1);

% Newton's method
while (norm(df(x)) > tol) && (k < maxit)

    k = k + 1;

    % descent direction
    p = -B * df(x);

    % line search

    % exact line search
    % fa = @(a) f(x + a * p);
    % [a, ~, ~] = golden_search(fa, a, 1e-3, 300);

    % Armijo
    % [a, ~] = Armijo(f, df, x, p, 0.5, 1e-4, 300);

    % Wolfe
    [a, ~] = Wolfe(f, df, x, p, 1e-4, 0.9, 300);

    % assign value
    xhist(k, :) = x;
    ahist(k) = a;
    fhist(k) = f(x);

    % B_(k+1)
    x1 = x + a * p;
    s = a * p;
    y = df(x1) - df(x);

    B = B - (B * y * y.' * B) / (y.' * B * y) + (s * s.') / (y.' * s);

    % x_(k+1)
    x = x1;

    % check iteration
    if k == maxit
        warning('Newton method reach maximum iteration before solve')
    end

end

% final output
xmin = x;

% end function
end

%% Constraint Optimisation

% 7.2.1 Penalty Method
function xmin = penalty_method(f, df, h, dh, g, dg, x0, mu0, mumax, grow, tol)

% input:
% f      - f(x)
% df     - f'(x)
% h      - equality constraint
% dh     - h'(x)
% g      - inequality constraint
% dg     - g'(x)
% x0     - initial guess
% mu0    - initial guess on penalty term
% mumax  - maximum allowable penalty term
% grow   - penalty term growth rate
% tol    - tolerance

% output:
% xmin   - local minimiser

% initialisation
x = x0;
mu = mu0;
violation = norm([h(x); max(0, g(x))]);

% search iteratively
while (violation > tol) && (mu < mumax)

    % penalty function
    phi = @(x) f(x) + ...
        0.5 * mu * sum(h(x) .^ 2) + ...
        0.5 * mu * sum(max(0, g(x)).^ 2);
    dphi = @(x) df(x) + ...
        mu * dh(x).' * h(x) + ...
        mu * dg(x).' * max(0, g(x));

    % unconstraint minimisation
    [x, ~, ~, ~] = gradient_descent(phi, dphi, x, 1e-3, 1000);

    mu = mu * grow;

    violation = norm([h(x); max(0, g(x))]);

    % check iteration
    if mu >= mumax
        warning('mu reach its maximum value before x close enough to feasible region')
    end

end

% final output
xmin = x;

% end function
end


% 7.2.3 Augmented Lagrangian Method
function xmin = ALM(f, df, h, dh, g, dg, x0, mu0, maxit, grow, tol)

% input:
% f      - f(x)
% df     - f'(x)
% h      - equality constraint
% dh     - h'(x)
% g      - inequality constraint
% dg     - g'(x)
% x0     - initial guess
% mu0    - initial guess on penalty term
% maxit  - maximum iterations
% grow   - penalty term growth rate
% tol    - tolerance

% output:
% xmin   - local minimiser

% initialisation
k = 0;
x = x0;
mu = mu0;
lambda = mu * h(x);
rho = max(0, mu * g(x));
violation = norm([h(x); max(0, g(x))]);

% search iteratively
while (violation > tol) && (k < maxit)
    k = k + 1;

    % augmented Lagrangian function
    phi = @(x) f(x) + ...
        lambda.' * h(x) + ...
        rho.' * max(0, g(x)) + ...
        0.5 * mu * (sum(h(x) .^ 2) + ...
        sum(max(0, g(x)).^ 2));
    dphi = @(x) df(x) + ...
        dh(x).' * lambda + ...
        dg(x).' * (rho .* double(g(x) > 0)) + ...
        mu * dh(x).' * h(x) + ...
        mu * dg(x).' * max(0, g(x));

    % unconstraint minimisation
    [x, ~, ~, ~] = gradient_descent(phi, dphi, x, 1e-3, 1000);
    lambda = lambda + mu * h(x);
    rho = max(0, rho + mu * g(x));

    mu = mu * grow;

    violation = norm([h(x); max(0, g(x))]);

    % check iteration
    if k == maxit
        warning('ALM reach maximum iteration before solved')
    end

end

% final output
xmin = x;

% end function
end
