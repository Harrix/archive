package ru.uchimznaem.uchimznaemhelper;

import android.content.Intent;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.graphics.drawable.GradientDrawable;
import android.net.Uri;
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

import java.io.IOException;


public class MainActivity extends AppCompatActivity implements
        NavigationView.OnNavigationItemSelectedListener,
        OnQRFragmentDataListener,
        OnMainFragmentDataListener {

    private static final String TAG = "uz-helper";
    public static final String FRAGMENT_STATE_KEY = "MainActivityFragmentStateKey";
    public static final int MAIN_FRAGMENT = -1;
    public static final int QR_FRAGMENT = 1;
    public static final int CONTACTS_FRAGMENT = 2;
    public static final int TREATMENTS_FRAGMENT = 3;
    public static final int EVENTS_FRAGMENT = 4;
    public static final int QUESTION_FRAGMENT = 5;
    public static final int ONKO_BOOK_FRAGMENT = 6;
    private static final int ROOMS_FRAGMENT = 7;

    private FrameLayout fragmentContainer;
    private FragmentManager fragmentManager;
    private DrawerLayout drawer_layout;

    public DatabaseHelper mDBHelper;
    public SQLiteDatabase mDb;

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

        Intent intent = getIntent();
        int fragmentCode = intent.getIntExtra(FRAGMENT_STATE_KEY, MAIN_FRAGMENT);
        setFragmentByCode(fragmentCode);
    }

    private void setFragmentByCode(int fragmentCode) {
        Fragment fragment;
        switch (fragmentCode) {
            case QR_FRAGMENT:
                fragment = new QRFragment();
                break;
            case CONTACTS_FRAGMENT:
                fragment = new ContactsFragment();
                break;
            case TREATMENTS_FRAGMENT:
                fragment = new TreatmentsFragment();
                break;
            case EVENTS_FRAGMENT:
                fragment = new EventsFragment();
                break;
            case QUESTION_FRAGMENT:
                fragment = new QuestionFragment();
                break;
            case ONKO_BOOK_FRAGMENT:
                fragment = new OnkoBooksFragment();
                break;
            case ROOMS_FRAGMENT:
                fragment = new RoomsListFragment();
                break;
            default:
                fragment = new MainFragment();
        }

        Log.d(TAG, "Restored fragment: " + fragment.toString());
        setFragment(fragment);
    }

    public void setFragment(Fragment f) {
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

        if (id == R.id.nav_where_i) {
            setFragmentByCode(QR_FRAGMENT);
        } else if (id == R.id.nav_rooms) {
            setFragmentByCode(ROOMS_FRAGMENT);
        } else if (id == R.id.nav_how_to_get) {
            Intent intent = new Intent(this, MapActivity.class);
            startActivity(intent);
        } else if (id == R.id.nav_how_to_contact) {
            setFragmentByCode(CONTACTS_FRAGMENT);
        } else if (id == R.id.nav_how_to_treat) {
            setFragmentByCode(TREATMENTS_FRAGMENT);
        } else if (id == R.id.nav_what_events) {
            setFragmentByCode(EVENTS_FRAGMENT);
        } else if (id == R.id.nav_question) {
            setFragmentByCode(QUESTION_FRAGMENT);
        } else if (id == R.id.nav_uchimznaem) {
            String url = "http://uchimznaem.ru";
            Intent i = new Intent(Intent.ACTION_VIEW);
            i.setData(Uri.parse(url));
            startActivity(i);
        } else if (id == R.id.nav_home) {
            setFragmentByCode(MAIN_FRAGMENT);
        } else if (id==R.id.nav_books){
            setFragmentByCode(ONKO_BOOK_FRAGMENT);
        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    @Override
    public void onQRFragmentDataListener(String string) {
        //Toast.makeText(getApplicationContext(), string, Toast.LENGTH_SHORT).show();

        Fragment fragment = new RoomFragment();

        Bundle bundle = new Bundle();
        bundle.putString("message", string);
        fragment.setArguments(bundle);

        setFragment(fragment);
    }

    @Override
    public void onMainFragmentDataListener(int position) {
        if (position == 0) {
            Intent intent = new Intent(this, MapActivity.class);
            startActivity(intent);
        } else if (position == QR_FRAGMENT) {
            Fragment fragment = new QRFragment();
            setFragment(fragment);
        } else if (position == CONTACTS_FRAGMENT) {
            Fragment fragment = new ContactsFragment();
            setFragment(fragment);
        } else if (position == TREATMENTS_FRAGMENT) {
            setFragment(new TreatmentsFragment());
        } else if (position == EVENTS_FRAGMENT) {
            Fragment fragment = new EventsFragment();
            setFragment(fragment);
        } else if (position == QUESTION_FRAGMENT) {
            Fragment fragment = new QuestionFragment();
            setFragment(fragment);
        } else if (position == ONKO_BOOK_FRAGMENT) {
            Fragment fragment = new OnkoBooksFragment();
            setFragment(fragment);
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mDb.close();
        mDBHelper.close();
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        Fragment container = fragmentManager.findFragmentById(R.id.fragmentContainer);

        int value = MAIN_FRAGMENT;
        if (container instanceof QRFragment) {
            value = QR_FRAGMENT;
        } else if (container instanceof ContactsFragment) {
            value = CONTACTS_FRAGMENT;
        } else if (container instanceof TreatmentsFragment) {
            value = TREATMENTS_FRAGMENT;
        } else if (container instanceof EventsFragment) {
            value = EVENTS_FRAGMENT;
        } else if (container instanceof QuestionFragment) {
            value = QUESTION_FRAGMENT;
        } else if (container instanceof OnkoBooksFragment) {
            value = ONKO_BOOK_FRAGMENT;
        } else if (container instanceof RoomsListFragment) {
            value = ROOMS_FRAGMENT;
        }
        Log.d(TAG, "MAIN_ACTIVITY_FRAGMENT = " + String.valueOf(value));
        outState.putInt(FRAGMENT_STATE_KEY, value);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        int value = savedInstanceState.getInt(FRAGMENT_STATE_KEY, MAIN_FRAGMENT);
        setFragmentByCode(value);
    }
}