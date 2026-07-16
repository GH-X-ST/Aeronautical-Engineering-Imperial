%% Housekeeping
clear
clc

%% Test


%% 9.2.2 Finite Difference Approximations

% Finite difference
function Jx = finite_diff(F, x, h)

% input:
% F  - F(x)
% x  - x
% h  - step size

% output:
% Jx - Jacobian

% initialisation
Fx = F(x);

n = length(x);
m = length(Fx);

Jx = zeros(m, n);

% find jacobian
for i = 1 : n

    xp = x;
    xp(i) = x(i) + h;

    Jx(:, i) = (F(xp) - Fx) ./ h;

end

% end function
end


% Central difference
function Jx = central_diff(F, x, h)

% input:
% F  - F(x)
% x  - x
% h  - step size

% output:
% Jx - Jacobian at x

% initialisation
Fx = F(x);

m = length(Fx);
n = length(x);

Jx = zeros(m, n);

% find Jacobian
for i = 1 : n

    xp = x;
    xp(i) = x(i) + h;

    xm = x;
    xm(i) = x(i) - h;

    Jx(:, i) = (F(xp) - F(xm)) ./ (2 * h);

end

% end function
end

%% 9.2.2 Complex-Step Differentiation

function Jx = complex_diff(F, x, h)

% input:
% F  - F(x)
% x  - x
% h  - step size

% output:
% Jx - Jacobian at x

% initialisation
Fx = F(x);

m = length(Fx);
n = length(x);

Jx = zeros(m, n);

% find Jacobian
for i = 1 : n

    xi = x;
    xi(i) = x(i) + 1i * h;

    Jx(:, i) = imag(F(xi)) ./ h;

end

% end function
end

%% 9.3 Reverse-Mode Automatic Differentiation

function Jx = ad_diff(F, x)

% input:
% F  - F(x)
% x  - x
%
% output:
% Jx - Jacobian

% initialisation
x = dlarray(x);

% execute functin in tracing mode
Jx = dlfeval(@ad_jacob, F, x);

% convert result back to double
Jx = extractdata(Jx);

% end function
end

% helper
function Jx = ad_jacob(F, x)

% input:
% F  - F(x)
% x  - x

% output:
% Jx - Jacobian in dlarray

% initialisation
Fx = F(x);

m = length(Fx);
n = length(x);

Jx = zeros(n, m);
Jx = dlarray(Jx);

% compute Jacobian
for i = 1 : m
    Jx(:, i) = dlgradient(Fx(i), x, 'RetainData', true);
end

Jx = Jx.';

% end function
end