%% Numerical PDE Solving MATH433 2/6
%Define our domain
a = 0; b = 2*pi; N = 100;
dx = (b-a)/N;
x = a:dx:b; 

% Defining our U(x) = cos(x), as well as an empty array for the derivative
u = cos(x);
dudx = zeros(size(u));

% Numerically Calculating the Derivative du/dx
for j=1:N
    dudx(j) = (u(j+1)-u(j))/dx;
end
dudx(end) = (u(end)-u(end-1))/dx;

% Plotting our function and its derivative
figure()
plot(x, u, 'LineWidth', 2)
hold on 
plot(x, dudx, 'LineStyle','--', 'Color', 'r', 'LineWidth', 2); xlim([0 2*pi]);

%% Solving the Linear Transport Equation
% u_t + cu_x = 0
c = 1;
%Define our domain
a = -10; b = 10; N = 200;
dx = (b-a)/N;
x = a:dx:b; 

%Define our time
tend = 10; Nt = 200;
dt = tend/Nt;
t = 0:dt:tend;

%Initialize our solution matrix u: each row is a fixed time, each column a
%fixed x
u = zeros(Nt+1, N+1);

%Initial Condition
u(1, :) = exp(-x.^2);

%Boundary Condition
u(:, 1) = 0;

%March through time and space
for n=1:Nt %Nt = length(t) -1
    for j = 2:length(x) % N = length(x) -1
        u(n+1, j) = u(n, j) - c*dt/dx*(u(n, j) - u(n, j-1));
    end
end

figure()
for n = 1:length(t)
    plot(x, u(n, :), 'k');
    pause(0.1);
end


