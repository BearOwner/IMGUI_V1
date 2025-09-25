package com.bearmod;
import android.app.Activity;
import android.os.Bundle;

public class MainActivity extends Activity {
	
	
     static {
         System.loadLibrary("bearmod");

     }

     @Override
     protected void onCreate(Bundle savedInstanceState) {
         super.onCreate(savedInstanceState);
         Launcher.Init(this);
     }
}
  
