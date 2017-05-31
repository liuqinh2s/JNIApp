package com.example.liuqinh2s.jniapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    public float m_FOV = 0.0f;
    public int m_InterpolateType = 0;
    public int m_MediaType = 0;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
//        tv.setText(dynamicGenerateKey("hello"));
        stringFromJNI();
        tv.setText(m_MediaType+""+m_FOV+m_InterpolateType);

    }

    //静态注册

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    //动态注册

    //测试动态方法Jni
    public native String dynamicGenerateKey(String name);

}
