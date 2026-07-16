%% Housekeeping
clear
clc

%% Test


%% 10.2 Design of Experiments

% 10.2.1 Full Factorial Designs
function X = full_factorial(XL, XU, level)

% inputs:
% XL    - lower bound, n x 1
% XU    - upper bound, n x 1
% level - sampling level, n x 1mu

% outputs:
% X     - sampling points, N x n

% initialisation
n = length(XL);

% linspace
grid = cell(n, 1);

for i = 1 : n
    grid{i} = linspace(XL(i), XU(i), level(i));
end

% meshgrid
G = cell(n, 1);
[G{:}] = ndgrid(grid{:});

% flattern
N = numel(G{1});
X = zeros(N, n);

for i = 1 : n
    X(:, i) = G{i}(:);
end

% end function
end


% 10.2.2 Latin Hypercube Sampling (LHS)
function X = LHC(XL, XU, N)

% input:
% XL - lower bound, n x 1
% XU - upper bound, n x 1
% N  - number of sampling points, N

% output:
% X  - sampling points, N x n

% initialisation
n = length(XL);
X01 = zeros(N, n);

% sampling use random permutation
for i = 1 : n
    p = randperm(N).';
    X01(:, i) = (p - rand(N, 1)) / N;
end

% scaling to bounds
X = XL.' + (XU.' - XL.') .* X01;

% end function
end


% 10.2.2 Optimum Latin Hypercube Sampling
function Xopt = LHC_Opt(XL, XU, N, maxit)

% input:
% XL    - lower bound, n x 1
% XU    - upper bound, n x 1
% N     - number of sampling points, N
% maxit - mximum number of iterations

% output:
% Xopt  - sampling points, N x n

% initialisation
n = length(XL);
X = zeros(N, n);
Xopt = zeros(N, n);

k = 0;
dmin_all = 0;

% iterate to find the maximum minimum distance
while k < maxit
    k = k + 1;

    % compute LHC in current iteration
    X = LHC(XL, XU, N);

    % find minimum distance of current sample
    dmin = inf;

    for i = 1 : N - 1
        for j = i + 1 : N
            d = sum((X(i, :) - X(j, :)) .^ 2);
            dmin = min(dmin, d);
        end
    end

    % check if current iteration distance is larger
    if dmin > dmin_all
        dmin_all = dmin;
        Xopt = X;
    end
end

% end function
end

%% 10.3 Surrogate Modeling Techniques

% 10.3.1 Response Surface Equations (Polynomial Regression)
function f = LS_2D(X, y)

% input:
% X - sampling points, N x 2
% y - sampling data, N x 1

% output:
% f - fitted functions, f(x1, x2)

% initialisation
N = length(y);

% construct dataset
X1 = X(:, 1);
X2 = X(:, 2);
A = [ones(N, 1), X1, X2, X1 .^ 2, X2 .^ 2, X1 .* X2];

% fitted the function using least square
c = A \ y;

% construct result function
f = @(x1, x2) c(1) + c(2) .* x1 + c(3) .* x2 + ...
    c(4) .* x1 .^ 2 + c(5) .* x2 .^ 2 + c(6) .* x1 .* x2;

% end function
end


% Moving least square
function yout = MLS_2D(X, y, x, theta)

% input:
% X     - sampling points, N x 2
% y     - sampling data, N x 1
% x     - input point, 2 x 1
% theta - weight average scaling factor

% output:
% yout  - output value at input point x

% initialisation
N = length(y);

% construct sampling matrix
X1 = X(:, 1);
X2 = X(:, 2);
A = [ones(N, 1), X1, X2, X1 .^ 2, X2 .^ 2, X1 .* X2];

% construct weighted matrix
d = (x(1) - X1) .^ 2 + (x(2) - X2) .^ 2;
w = exp(-theta .* d);
w = diag(w);

% calculate the result
c = (A.' * w * A) \ (A.' * w * y);
Aout = [1, x(1), x(2), x(1) ^ 2, x(2) ^ 2, x1 * x2];
yout = Aout * c;

% end function
end

% Radial Basis Function (RBF)
function yout = RBF_2D(X, y, x, theta)

% input:
% X     - sampling points, N x n
% y     - sampling value, N x 1
% x     - input function, 2 x 1
% theta - scaling factor

% output:
% yout  - output fitted value

% initialisation
N = length(y);

X1 = X(:, 1);
X2 = X(:, 2);

K = zeros(N);

% construct covariance matrix
for i = 1 : N
    for j = 1 : N
        d = (X1(i) - X1(j)) ^ 2 + (X2(i) - X2(j)) ^ 2;
        K(i, j) = exp(-d * theta);
    end
end

% fit the data
w = K \ y;

% covariance of the input
dout = (x(1) - X1(i)) .^ 2 + (x(2) - X2(i)) .^ 2;
Kout = exp(-theta .* dout.');

% yield output
yout = Kout * w;

% end function
end