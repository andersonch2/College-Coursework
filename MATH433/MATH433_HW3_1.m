%% MATH 433 HW 2 Cade Anderson
%Solving the Cauchy Problem:
% u_t + cu_x = 0 xE[0, 6] t>0
%u(x, 0) = exp(-x)
%u(0, t) = 1


c = 1;
%Define our domain, note that we discretize our space using dx, rather than
%N
a = 0; b = 6; dx = 0.005;
N = (b-a)/dx;
x = a:dx:b; 

%Define our time
tend = 3; dt = 0.01;
Nt = tend/dt;
t = 0:dt:tend;

%Initialize our solution matrix u: each row is a fixed time, each column a
%fixed x
u = zeros(Nt+1, N+1);

%Initial Condition
u(1, :) = exp(-x);

%Boundary Condition
u(:, 1) = 1;

%March through time and space
for n=1:Nt %Nt = length(t) -1
    for j = 2:length(x) % N = length(x) -1
        u(n+1, j) = u(n, j) - c*dt/dx*(u(n, j) - u(n, j-1));
    end
end

figure()
plot(x, u(1, :), 'LineWidth', 2)
hold on
plot(x, u(101, :), 'LineWidth', 2, 'LineStyle','--')
plot(x, u(201, :), 'LineWidth', 2, 'LineStyle','-.')
plot(x, u(301, :), 'LineWidth', 2, 'LineStyle',':')
grid on; title('\Deltax = 0.005 \Deltat = 0.01'); xlabel('x'); ylabel('u(x, t)');
legend('t = 0', 't = 1', 't = 2', 't = 3'); 

