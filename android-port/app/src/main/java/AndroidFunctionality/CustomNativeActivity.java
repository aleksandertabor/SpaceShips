package AndroidFunctionality;

import android.app.AlertDialog;
import android.app.NativeActivity;
import android.content.Context;
import android.os.Build;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.util.Log;
import android.widget.Button;
import android.widget.Toast;

public class CustomNativeActivity extends NativeActivity {


    private static final String TAG = "MyActivity";

    @Override
    protected void onStart() {
        super.onStart();
        Log.v(TAG, "onStart");
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.v(TAG, "onResume");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.v(TAG, "onPause");
    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.v(TAG, "onStopEvent");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.v(TAG, "onDestroy");
    }


    public void FinishProcess() {
        android.os.Process.killProcess(android.os.Process.myPid());
    }

    public void Vibrate(final String message) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder = new AlertDialog.Builder(CustomNativeActivity.this);
                builder.setTitle("Message for players");
                builder.setMessage(message);

                builder.create().show();
            }
        });


        Vibrator v = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
// Vibrate for 500 milliseconds
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            v.vibrate(VibrationEffect.createOneShot(200, VibrationEffect.DEFAULT_AMPLITUDE));
        } else {
            //deprecated in API 26
            v.vibrate(200);
        }
    }

    public void saveToast(final String playerName, final String highscorePoints) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Context context = getApplicationContext();
                CharSequence text = "Congrats " + playerName + "! You're on the TOP5. Your score: " + highscorePoints + " points.";
                int duration = Toast.LENGTH_LONG;
                Toast toast = Toast.makeText(context, text, duration);
                toast.show();

                Button button = new Button(CustomNativeActivity.this);
                button.setText("CONTINUE");
            }
        });
    }


}
