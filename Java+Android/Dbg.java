package com.example.seung.hellotf;
import android.util.Log;

public final class Dbg {
	 private Dbg (){}

	    public static void out (Object msg){
	        Log.i ("info", msg.toString ());
	    }
}

