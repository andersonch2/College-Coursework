%% MATH 433 HW 2 Cade Anderson
%Solving the Cauchy Problem:
% u_t + cu_x = 0 xE[0, 6] t>0
%u(x, 0) = exp(x-6)
%u(6, t) = 1


c = -1;
%Define our domain, note that we discretize our space using dx, rather than
%N
a = 0; b = 6; dx = 0.01;
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
u(1, :) = exp(x-6);

%Boundary Condition
u(:, end) = 1;

%March through time and space
for n=1:Nt %Nt = length(t) -1
    for j = 1:length(x)-1 % N = length(x) -1
        %NOTE: Forward Difference Method
        u(n+1, j) = u(n, j) - c*dt/dx*(u(n, j+1) - u(n, j));
    end
end

figure()
plot(x, u(1, :), 'LineWidth', 2)
hold on
plot(x, u(101, :), 'LineWidth', 2, 'LineStyle','--')
plot(x, u(201, :), 'LineWidth', 2, 'LineStyle','-.')
plot(x, u(301, :), 'LineWidth', 2, 'LineStyle',':')
grid on; title('\Deltax = 0.01 \Deltat = 0.01'); xlabel('x'); ylabel('u(x, t)');
legend('t = 0', 't = 1', 't = 2', 't = 3'); 

