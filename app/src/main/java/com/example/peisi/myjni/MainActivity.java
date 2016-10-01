package com.example.peisi.myjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.example.peisi.jnitest.JniUtils;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        System.out.println(JniUtils.getStringFormC());
        ((TextView)findViewById(R.id.tv1)).setText(JniUtils.getStringFormC());
    }
}
