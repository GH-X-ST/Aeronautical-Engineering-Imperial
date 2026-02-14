function [t, y] = RungeKutta4(f, t0, tf, y0, h)
% This function could solve initial value problem by 
% 4th order Runge-Kutta Method.
%
% RungeKutta4(f, t0, tf, y0, h)
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

    k1 = h * f(t(i), y(:, i));
    k2 = h * f(t(i) + h / 2, y(:, i) + k1 / 2);
    k3 = h * f(t(i) + h / 2, y(:, i) + k2 / 2);
    k4 = h * f(t(i) + h, y(:, i) + k3);

    y(:, i+1) = y(:, i) + k1 / 6 + (k2 + k3) / 3 + k4 / 6;

end