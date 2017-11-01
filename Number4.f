c the roots of the quadratic equation
	a=1.0
	b=3.0
	c=-5.6
	x1=(-b+sqrt(b*b-4.0*a*c))/(2.0*a)
	x2=(-b-sqrt(b*b-4.0*a*c))/(2.0*a)
	write(*,100)x1,x2
100	format(1x,'x1=',f6.2,'x2=',f6.2)
	end