package ru.uchimznaem.uchimznaemhelper;

import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.drawable.GradientDrawable;
import android.os.Build;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.util.Log;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.ViewTreeObserver;
import android.widget.FrameLayout;
import android.widget.Toast;

import java.io.IOException;

public class MainActivity extends AppCompatActivity implements
        NavigationView.OnNavigationItemSelectedListener,
        OnQRFragmentDataListener,
        OnMainFragmentDataListener {

    private static final String TAG = "uz-helper";
    private FrameLayout fragmentContainer;
    private FragmentManager fragmentManager;
    private DrawerLayout drawer_layout;

    private DatabaseHelper mDBHelper;
    private SQLiteDatabase mDb;

    public int height;
    public int width;

    private OnActivityDataListener mListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        mDBHelper = new DatabaseHelper(this);

        try {
            mDBHelper.updateDataBase();
        } catch (IOException mIOException) {
            throw new Error("UnableToUpdateDatabase");
        }

        try {
            mDb = mDBHelper.getWritableDatabase();
        } catch (SQLException mSQLException) {
            throw mSQLException;
        }

        drawer_layout = (DrawerLayout) findViewById(R.id.drawer_layout);

        drawer_layout.getViewTreeObserver().addOnGlobalLayoutListener(new ViewTreeObserver.OnGlobalLayoutListener() {
            @Override
            public void onGlobalLayout() {
                height = drawer_layout.getHeight();
                width = drawer_layout.getWidth();

                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN) {
                    drawer_layout.getViewTreeObserver().removeOnGlobalLayoutListener(this);
                    drawer_layout.getHeight(); //height is ready

                    GradientDrawable gd = new GradientDrawable(
                            GradientDrawable.Orientation.TOP_BOTTOM,
                            new int[]{getResources().getColor(R.color.colorGradientBegin), getResources().getColor(R.color.colorGradientEnd)});
                    gd.setCornerRadius(0f);
                    gd.setGradientType(GradientDrawable.RADIAL_GRADIENT);
                    gd.setGradientRadius(Math.max(drawer_layout.getWidth(), drawer_layout.getHeight()));
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN) {
                        drawer_layout.setBackground(gd);
                    } else {
                        drawer_layout.setBackgroundDrawable(gd);
                    }
                }
            }
        });

        fragmentContainer = (FrameLayout) findViewById(R.id.fragmentContainer);
        fragmentManager = getSupportFragmentManager();

        //Main Fragment
        Fragment fragment = new MainFragment();
        setFragment(fragment);
    }

    void setFragment(Fragment f){
        Fragment container = fragmentManager.findFragmentById(R.id.fragmentContainer);

        if (container == null) {
            Log.d(TAG, " fragment == null");
            fragmentManager.beginTransaction()
                    .add(R.id.fragmentContainer, f)
                    .commit();
            Log.d(TAG, "fragment changed to " + f.toString());
        } else {
            Log.d(TAG, "fragment is not null");
            fragmentManager.beginTransaction()
                    .replace(R.id.fragmentContainer, f)
                    .addToBackStack("replace")
                    .commit();
            Log.d(TAG, "fragment changed to " + f.toString());
        }
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();

        if (id == R.id.nav_camera) {
            //Fragment fragment = fragmentManager.findFragmentById(R.id.fragmentContainer);
            Fragment fragment = new QRFragment();
            setFragment(fragment);
        } else if (id == R.id.rooms_list) {
            Fragment fragment = new RoomsListFragment();
            setFragment(fragment);
        } else if (id == R.id.nav_slideshow) {

        } else if (id == R.id.nav_manage) {

        } else if (id == R.id.nav_share) {

        } else if (id == R.id.nav_send) {

        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    @Override
    public void onQRFragmentDataListener(String string) {
        Toast.makeText(getApplicationContext(), string, Toast.LENGTH_SHORT).show();

        Fragment fragment = fragmentManager.findFragmentById(R.id.fragmentContainer);
        fragment = new RoomFragment();

        Bundle bundle = new Bundle();
        bundle.putString("message", string);
        fragment.setArguments(bundle);

        setFragment(fragment);
    }

    @Override
    public void OnMainFragmentDataListener(int position) {
        Toast.makeText(getApplicationContext(), "Tile " + position,
                Toast.LENGTH_SHORT).show();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mDb.close();
        mDBHelper.close();
    }
}
