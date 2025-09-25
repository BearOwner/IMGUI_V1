package com.bearmod;
import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Build;
import android.provider.Settings;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.Toast;
import android.graphics.drawable.GradientDrawable;
import android.graphics.Color;
import android.widget.TextView;
import android.view.Gravity;
import android.app.Dialog;
import android.os.Handler;
import android.os.Message;
import android.app.Activity;

import java.util.Objects;


public class Launcher {

    public static Activity d_activity;

    public static native String LoginNameNrg();
    public static native String Pleaselog();
    public static native String KeyAdd();
    public static native String Login();
    public static native String Cancel();
    public static native String Error();
    public static native String Pleasecheck();
    public static native String Ok();
    public static native String Loging();
    public static native String Link();
    

    static{
        System.loadLibrary("bearmod");
    }
    private static SharedPreferences gifs;

    public static void Init(Object object) {
        final Context context = (Context) object;
        Activity m_Activity = (Activity) object;
        final Activity ggActivity = (Activity) object;
        Init(context);
         d_activity = m_Activity;


        if (!Settings.canDrawOverlays(context)) {
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + context.getPackageName()));
            m_Activity.startActivity(intent);
        }


        gifs = context.getSharedPreferences(context.getPackageName(), Context.MODE_PRIVATE);

        if (!gifs.contains("USER_KEY")) {


            final SharedPreferences sharedPreferences = context.getSharedPreferences("SavePref", 0);
            String string = sharedPreferences.getString("User", null);
            String string2 = sharedPreferences.getString("Pass", null);

            //Create LinearLayout
            LinearLayout linearLayout = new LinearLayout(context);
            linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
            linearLayout.setOrientation(LinearLayout.VERTICAL);
            GradientDrawable gradientdrawable = new GradientDrawable();
            gradientdrawable.setCornerRadius(30); //Set corner
            gradientdrawable.setColor(Color.parseColor("#FFF1F1F1")); //Set background color
            gradientdrawable.setStroke(0, Color.parseColor("#32cb00")); //Set 
            linearLayout.setBackground(gradientdrawable);



            TextView txt = new TextView(context);
            txt.setGravity(Gravity.CENTER);
            txt.setText(LoginNameNrg());
            //txt.setText("Login");
            txt.setTextColor(0xFF181818);
            txt.setBackgroundColor(Color.TRANSPARENT);
            txt.setTextSize(19);
            txt.setPadding(1,1,1,1);




            TextView txt1 = new TextView(context);
            txt1.setGravity(Gravity.CENTER);
            txt1.setText(Pleaselog());
            //txt1.setText("Please log in");
            txt1.setTextColor(0xFF151515);
            txt1.setBackgroundColor(Color.TRANSPARENT);
            txt1.setTextSize(9);


            final EditText editTextUser = new EditText(context);
            editTextUser.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
            editTextUser.setTextColor(Color.parseColor("#000000bb"));
            editTextUser.setHint(KeyAdd());
      //      editTextUser.setTextSize(10);//add
            editTextUser.setGravity(Gravity.CENTER);
            editTextUser.setTextColor(Color.parseColor("#000000")); // Черный текст


            editTextUser.setBackgroundColor(Color.parseColor("#000000")); // Черный цвет
            editTextUser.setHintTextColor(Color.parseColor("#000000")); // Черный цвет подсказки


            GradientDrawable strokeDrawable = new GradientDrawable();
            strokeDrawable.setShape(GradientDrawable.RECTANGLE);
            strokeDrawable.setColor(Color.parseColor("#fafafa")); // Красный цвет
            strokeDrawable.setCornerRadius(20); //Set corner
            strokeDrawable.setStroke(30, Color.TRANSPARENT); // Толщина обводки 30 и черный цвет

            editTextUser.setBackground(strokeDrawable);

            LinearLayout ln3 = new LinearLayout(context);
            ln3.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, (int)1));
            ln3.setOrientation(LinearLayout.HORIZONTAL);
            ln3.setGravity(Gravity.CENTER);
            ln3.setBackgroundColor(Color.GRAY);


            LinearLayout ln2 = new LinearLayout(context);
            ln2.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, -1));
            ln2.setOrientation(LinearLayout.HORIZONTAL);
            ln2.setGravity(Gravity.CENTER);


            Button button = new Button(context);
            button.setTextColor(Color.BLUE);
            button.setText(Login());
            //button.setText("                Login                ");
            button.setBackgroundColor(Color.TRANSPARENT);



            LinearLayout ln4 = new LinearLayout(context);
            ln4.setLayoutParams(new LinearLayout.LayoutParams((int)1,LinearLayout.LayoutParams.MATCH_PARENT));
            ln4.setOrientation(LinearLayout.HORIZONTAL);
            ln4.setGravity(Gravity.CENTER);
            ln4.setBackgroundColor(Color.GRAY);



            //Create button
            Button button2 = new Button(context);
            button.setTextColor(Color.BLUE);
            button2.setText(Cancel());
            //button2.setText("               Cancel                ");
            button2.setBackgroundColor(Color.TRANSPARENT);


            linearLayout.addView(txt);
            linearLayout.addView(txt1);
            linearLayout.addView(editTextUser);

            linearLayout.addView(ln3);
            ln2.addView(button2);
            ln2.addView(ln4);
            ln2.addView(button);
            linearLayout.addView(ln2);
            //Create alertdialog

            final Dialog builder = new Dialog(context);
            //builder.setTitle("Login");
            builder.setCancelable(false);
            builder.setContentView(linearLayout);
            Objects.requireNonNull(builder.getWindow()).setBackgroundDrawableResource(android.R.color.transparent);

            final EditText editText3 = editTextUser;

            button.setOnClickListener(view -> {
                String userKey = editTextUser.getText().toString();
                Login(context, userKey);
                builder.dismiss();
            });

            button2.setOnClickListener(view -> {


                Intent intent = new Intent(Intent.ACTION_VIEW);
                intent.setData(Uri.parse(Link()));
                ggActivity.startActivity(intent);

            });
            builder.show();
        } else{
            Login(context, gifs.getString("USER_KEY", null));
        }
    }



    private static void Login(final Context kontes, final String userKey) {
        LinearLayout linearLayout = new LinearLayout(kontes);
        linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        linearLayout.setOrientation(LinearLayout.VERTICAL);

        GradientDrawable gradientdrawable = new GradientDrawable();
        gradientdrawable.setCornerRadius(20); //Set corner
        gradientdrawable.setColor(Color.parseColor("#FFF1F1F1")); //Set background color
        gradientdrawable.setStroke(0, Color.parseColor("#32cb00")); //Set 
        linearLayout.setBackground(gradientdrawable);

        TextView txt = new TextView(kontes);

        txt.setGravity(Gravity.CENTER);
        txt.setText(Loging());
        
        //txt.setText("  Loging in...  ");
        txt.setTextColor(0xFF181818);
        txt.setBackgroundColor(Color.TRANSPARENT);
        txt.setTextSize(20);
        
    
        
        linearLayout.addView(txt);

        final Dialog builder = new Dialog(kontes);
        //builder.setTitle("Login");
        builder.setCancelable(false);
        builder.setContentView(linearLayout);
        Objects.requireNonNull(builder.getWindow()).setBackgroundDrawableResource(android.R.color.transparent);
    //    builder.getWindow().setFlags(WindowManager.LayoutParams.FLAG_SECURE,WindowManager.LayoutParams.FLAG_SECURE);
        
        builder.show();

        @SuppressLint("HandlerLeak") final  Handler sagen = new Handler() {
            @Override
            public void handleMessage(Message ems) {
                if (ems.what == 0) {
               //     Toast.makeText(this, "Key Work", 1).show();
                    Toast.makeText(kontes, "Key Work", Toast.LENGTH_LONG).show();
                    ImGui menu = new ImGui(kontes);
                 //  kontes.startService(new Intent(kontes, ImGui.class));
                } else if (ems.what == 1) {
                    LinearLayout linearLayout = new LinearLayout(kontes);
                    linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
                    linearLayout.setOrientation(LinearLayout.VERTICAL);

                    GradientDrawable gradientdrawable = new GradientDrawable();
                    gradientdrawable.setCornerRadius(30); //Set corner
                    gradientdrawable.setColor(Color.parseColor("#FFF1F1F1")); //Set background color
                    gradientdrawable.setStroke(0, Color.parseColor("#32cb00")); //Set 
                    linearLayout.setBackground(gradientdrawable);

                    //Create username edittext field
                    TextView txt = new TextView(kontes);
                    txt.setGravity(Gravity.CENTER);
                    txt.setText(Error());
                    //txt.setText("Error");
                    txt.setTextColor(0xFF181818);
                    txt.setBackgroundColor(Color.TRANSPARENT);
                    txt.setTextSize(20);

                    TextView txt1 = new TextView(kontes);
                    txt1.setGravity(Gravity.CENTER);
                    txt1.setText(Pleasecheck());
                    //txt1.setText("                               Please check your key                               ");
                    txt1.setTextColor(0xFF595959);
                    txt1.setBackgroundColor(Color.TRANSPARENT);
                    txt1.setTextSize(13);

                    final TextView infoText = new TextView(kontes);
                    infoText.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.WRAP_CONTENT));
                    infoText.setGravity(Gravity.CENTER);
                    infoText.setBackgroundColor(Color.TRANSPARENT);
                    infoText.setText(ems.obj.toString());
                    //Create password edittext field


                    LinearLayout ln3 = new LinearLayout(kontes);
                    ln3.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, (int)1));
                    ln3.setOrientation(LinearLayout.HORIZONTAL);
                    ln3.setGravity(Gravity.CENTER);
                    ln3.setBackgroundColor(Color.GRAY);


                    LinearLayout ln2 = new LinearLayout(kontes);
                    ln2.setLayoutParams(new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, -1));
                    ln2.setOrientation(LinearLayout.HORIZONTAL);
                    ln2.setGravity(Gravity.CENTER);


                    Button button = new Button(kontes);
                    button.setTextColor(Color.BLUE);
                    button.setText(Ok());
                    //button.setText("                         OK                         ");
                    button.setBackgroundColor(Color.TRANSPARENT);







                    linearLayout.addView(txt);
                    linearLayout.addView(txt1);
                    linearLayout.addView(infoText);
                    linearLayout.addView(ln3);

                    ln2.addView(button);
                    linearLayout.addView(ln2);
                    //Create alertdialog

                    final Dialog builder = new Dialog(kontes);
                    //builder.setTitle("Login");
                    builder.setCancelable(false);
                    builder.setContentView(linearLayout);
                    Objects.requireNonNull(builder.getWindow()).setBackgroundDrawableResource(android.R.color.transparent);


                    button.setOnClickListener(view -> System.exit(0));

                    builder.show();


                }
                builder.dismiss();
            }
        };

        new Thread(() -> {
            String result = Check(kontes, userKey);
            if (result.equals("OK")) {
                gifs.edit().putString("USER_KEY", userKey).apply();

                sagen.sendEmptyMessage(0);
            } else {
                gifs.edit().clear().apply();

                Message ems = new Message();
                ems.what = 1;
                ems.obj = result;
                sagen.sendMessage(ems);
            }
        }).start();


    } 
    private static native void Init(Context mContext);
    private static native String Check(Context mContext, String userKey);
    
    }


