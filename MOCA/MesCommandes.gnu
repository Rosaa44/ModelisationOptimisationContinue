set output "f0.png"
plot (-2)*exp(-(x+1)*(x+1))
set output "f2.png"
plot (1/2)*x*x-3*x*(log(x)-1)
set output "f1.png"
plot (1/4)*x*x*x*x-(2*x*x)+x

set output "f0'.png"
plot [] [-0.5:0.5] 4*(x+1)*exp(-(x+1)*(x+1))
set output "f1'.png"
plot [] [-50:50] x*x*x-4*x+1
set output "f2'.png"
plot [0:5] [-1:0] x-3*log(x)

