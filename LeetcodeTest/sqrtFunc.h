#pragma once
class sqrtFunc
{
public:
	sqrtFunc(void);
	~sqrtFunc(void);
	double mySqrt(int x)
	{
		if (x < 0)
		{
			return -1;
		}
	  double p = 1.0E-8;//��ȷ��С������λ
	  double q = 1.0E-5;
	  double mid = (double)x/2+1;
	  while (mid*mid -x>q||mid*mid-x<-q )
	  {
		  if (mid*mid -x>q)
			  mid = mid -q;
		  else
			  mid = mid +q;
	  }
	  return mid;
	}
};

