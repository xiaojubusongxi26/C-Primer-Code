int mySqrt(int x){
	double r = x + 0.001;
	while (true)
	{
		r = r - (pow(r,2)-x )/ (2*r);
		if ((pow(r, 2) - x) <1) break;
	}
	return r;
}