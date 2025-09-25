package com.bearmod;

import android.content.Context;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;


import android.view.Choreographer;
import android.view.WindowManager;


//public class GLES3JNIView extends SurfaceView implements SurfaceHolder.Callback {//test

public class GLES3JNIView extends GLSurfaceView implements GLSurfaceView.Renderer {

    private WindowManager.LayoutParams layoutParams;
	//private GLSurfaceView glSurfaceView;
	
	static{
		System.loadLibrary("bearmod");
	}
	
	
    public GLES3JNIView(Context context) {
        super(context);
        this.frameCallback = frameCallback;
        if (IsHide()){
        setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        getHolder().setFormat(-3);
        getHolder().lockCanvas(); //
        //getHolder().lockHardwareCanvas();//
        setEGLContextClientVersion(3);
       // getHolder().addCallback(this);
        setRenderer(this);
           // startRendering();
        requestRender();//
  
    
        }
    }

    
    public void onDrawFrame(GL10 gl) {
        if (IsHide()){
        step();
        //    startRendering();
        //    startRendering3();
        }
    }

    public void onSurfaceChanged(GL10 gl, int width, int height) {
        if (IsHide()){
        resize(width, height);
        }
    }

    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        if (IsHide()){
        init();
        //    startRendering();
        //    startRendering3();
        }
    }
    
    
    

    @Override
    protected void onDetachedFromWindow() {
        super.onDetachedFromWindow();
        imgui_Shutdown();
    }
    
        private Choreographer.FrameCallback frameCallback;
        private boolean isRendering = false;

    public static native void init();
    public static native void resize(int width, int height);
    public static native void step();
    public static native void imgui_Shutdown();
    public static native void MotionEventClick(boolean down,float PosX,float PosY);
    public static native String getWindowRect();
    private native boolean IsHide();

    public boolean isRendering() {
        return isRendering;
    }

    public void setRendering(boolean rendering) {
        isRendering = rendering;
    }
    //  public static native void Mode(int Game, int Root, int Bit);

    
    
}
