package com.example.seung.hellotf;

// Some useful Java functions
// written by Seung-Chan Kim

public class DDMath {
	
	public static void ShiftWithNewf(float[] arr, float n_val)
	{
		int sz = arr.length;
		int i;
		for(i=0; i< sz-1; i++)
		{
			arr[sz-1-i] = arr[sz-2-i];
		}
	
		arr[0] = n_val;
	}
	
	public static void ShiftWithNewd(int[] arr, int n_val)
	{
		int sz = arr.length;
		int i;
		for(i=0; i< sz-1; i++)
		{
			arr[sz-1-i] = arr[sz-2-i];
			
		}
	
		arr[0] = n_val;
	
	}
	

	public static void ShiftWithNewl(long[] arr, long n_val)
	{
		int sz = arr.length;
		int i;
		for(i=0; i< sz-1; i++)
		{
			arr[sz-1-i] = arr[sz-2-i];
			
		}
	
		arr[0] = n_val;
	
	}
    public static float ArrayMax(float [] arr) {
        float max = Float.NEGATIVE_INFINITY;

        for(float cur: arr)
            max = Math.max(max, cur);

        return max;
    }

	public static double ArrayMax(double [] arr) {
		double max = Double.NEGATIVE_INFINITY;

		for(double cur: arr)
			max = Math.max(max, cur);

		return max;
	}

    public static double[] SoftMax(double[] arr)
    {
        double vmax = ArrayMax(arr);

		int sz = arr.length;
        double [] arr2 = new double[sz];

		double sum_exp_a = 0;
        for(int i=0; i<sz; i++)
        {
            arr2[i] = arr[i] - vmax;

            double expa = Math.exp(arr2[i]);
			sum_exp_a += expa;
        }

		for(int i=0; i<sz; i++)
		{
			arr2[i] = Math.exp(arr2[i]) / sum_exp_a;
		}


        return arr2;
    }


	public static int GetMaxIndex(float[] arr)
	{
		int idxMax =-1;
		float valMax = -Float.MAX_VALUE;// -99999;

		int sz = arr.length;
		for(int i=0; i< sz; i++)
		{
			if(valMax <arr[i])
			{
				valMax = arr[i];
				idxMax = i;

			}
		}

		return idxMax;
	}
	
	
	
}
