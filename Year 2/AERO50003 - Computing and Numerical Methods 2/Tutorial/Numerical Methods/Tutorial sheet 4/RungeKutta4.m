function [X, V] = RungeKutta4(N, t, x0, v0, h, m, k, d)
% This function could solve mass-spring-system by 
% 4th order Runge-Kutta Method.
%
% ExplicitEuler(f, t0, tf, y0, h)
%
% outputs: X     -   displacement
%          V     -   velocity
% inputs:  N     -   number of masses
%          t     -   uniform grid points
%          x0    -   initial condition for displacement
%          v0    -   initial condition for displacement
%          m     -   mass (in matrix)
%          k     -   spring constant
%          d     -   damping constant

% Define the basic parameters
c = d ./ m;
Omg = sqrt(k ./ m);

% create empty matrix to store data for y
X = zeros(N + 2, length(t)); % displacement  % define X(0) and X(N+1) which both 0 at the end
V = zeros(N + 2, length(t)); % velocity      % define V(0) and V(N+1) which both 0 at the end

% Define the initial condition
X(2 : N + 1, 1) = x0;
V(2 : N + 1, 1) = v0;

% Compute the numerical solution
for i = 1 : length(t) - 1

    for j = 2 : N + 1

        kX1 = h * V(j, i);
        kV1 = h * (Omg(j - 1) ^ 2 * (X(j - 1, i) - 2 * X(j, i) + X(j + 1, i)) - c(j - 1) * V(j, i));

        kX2 = h * (V(j, i) + kX1 / 2);
        kV2 = h * (Omg(j - 1) ^ 2 * (X(j - 1, i) - 2 * (X(j, i) + kV1 / 2) + X(j + 1, i)) - c(j - 1) * V(j, i));

        kX3 = h * (V(j, i) + kX2 / 2);
        kV3 = h * (Omg(j - 1) ^ 2 * (X(j - 1, i) - 2 * (X(j, i) + kV2 / 2) + X(j + 1, i)) - c(j - 1) * V(j, i));

        kX4 = h * (V(j, i) + kX3);
        kV4 = h * (Omg(j - 1) ^ 2 * (X(j - 1, i) - 2 * (X(j, i) + kV3) + X(j + 1, i)) - c(j - 1) * V(j, i));

        X(j, i+1) = X(j, i) + kX1 / 6 + (kX2 + kX3) / 3 + kX4 / 6;
        V(j, i+1) = V(j, i) + kV1 / 6 + (kV2 + kV3) / 3 + kV4 / 6;
        
    end

end