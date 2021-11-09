(d,n,a)*f(d,n,b)>0) 
		continue;
	do
	{
		c=(a+b)/2; 
		e=f(d,n,c);
		printf("\n%9.3f%9.3f%9.3f\n",a,b,e);
		if(e*f(d,n,a)>0)