function [t, y] = Trapezoidal(f, t0, tf, y0, h)
% This function could solve initial value problem by 
% Trapezoidal Method.
%
% Trapezoidal(f, t0, tf, y0, h)
%
% outputs: t     -   uniform grid
%          y     -   numerical solution of y
% inputs:  f     -   function
%          t0    -   initial time
%          tf    -   final time
%          y0    -   initial condition
%          h     -   number of timestep

% define the uniform grid points
t = t0 : h : tf;

% create empty matrix to store data for y
y = zeros(length(y0), length(t));

% Define the initial condition
y(:, 1) = y0;

% Compute the numerical solution
for i = 1 : length(t) - 1

    % the algebraic equation at each time step 
    f_alg = @(y_next) (y(:, i) + ...
        (h / 2) * (f(t(i+1), y_next) + f(t(i), y(:, i))) - y_next);

    % approximate the equation by fsolve function base on yi
    y(:, i+1) = fsolve(f_alg, y(:, i));

end