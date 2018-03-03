package ru.uchimznaem.uchimznaemhelper;

import android.content.Context;
import android.content.res.Configuration;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.Display;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Toast;

/**
 * @author Vladimir Ulyanov
 */

public class MainFragment extends Fragment {

    private OnMainFragmentDataListener mListener;

    private GridView gridview;

    public MainFragment() {

    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        if (context instanceof OnQRFragmentDataListener) {
            mListener = (OnMainFragmentDataListener) context;
        } else {
            throw new RuntimeException(context.toString()
                    + " must implement OnMainFragmentDataListener");
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.fragment_main, container, false);
        gridview = root.findViewById(R.id.gridview);
        gridview.setAdapter(new ImageAdapter(getContext()));

        gridview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            public void onItemClick(AdapterView<?> parent, View v,
                                    int position, long id) {
                mListener.OnMainFragmentDataListener(position);
            }
        });

        if (isTablet(getContext())) {
            if (isLandscape(getContext()))
                gridview.setNumColumns(3);
            else
                gridview.setNumColumns(2);
        } else {
            if (isLandscape(getContext()))
                gridview.setNumColumns(2);
            else
                gridview.setNumColumns(1);
        }

        return root;
    }

    public class ImageAdapter extends BaseAdapter {
        private Context mContext;

        public ImageAdapter(Context c) {
            mContext = c;
        }

        public int getCount() {
            return mThumbIds.length;
        }

        public Object getItem(int position) {
            return null;
        }

        public long getItemId(int position) {
            return 0;
        }

        // create a new ImageView for each item referenced by the Adapter
        public View getView(int position, View convertView, ViewGroup parent) {
            ImageView imageView;
            if (convertView == null) {
                // if it's not recycled, initialize some attributes
                imageView = new ImageView(mContext);
                //imageView.setLayoutParams(new GridView.LayoutParams(300, 200));
                //imageView.setScaleType(ImageView.ScaleType.CENTER_CROP);
                //imageView.setPadding(20, 20, 20, 20);
                imageView.setAdjustViewBounds(true);

            } else {
                imageView = (ImageView) convertView;
            }

            imageView.setImageResource(mThumbIds[position]);
            return imageView;
        }

        // references to our images
        private Integer[] mThumbIds = {
                R.drawable.tile_how_to_get,
                R.drawable.tile_where_i,
                R.drawable.tile_how_to_contact,
                R.drawable.tile_how_to_treat,
                R.drawable.tile_what_events,
                R.drawable.tile_question,
                R.drawable.tile_books_2
                /*R.drawable.sample_3,
                R.drawable.sample_4, R.drawable.sample_5,
                R.drawable.sample_6, R.drawable.sample_7,
                R.drawable.sample_0, R.drawable.sample_1,
                R.drawable.sample_2, R.drawable.sample_3,
                R.drawable.sample_4, R.drawable.sample_5,
                R.drawable.sample_6, R.drawable.sample_7,
                R.drawable.sample_0, R.drawable.sample_1,
                R.drawable.sample_2, R.drawable.sample_3,
                R.drawable.sample_4, R.drawable.sample_5,
                R.drawable.sample_6, R.drawable.sample_7*/
        };
    }

    private void refreshGridView() {

        /*int gridViewEntrySize = getResources().getDimensionPixelSize(R.dimen.grip_view_entry_size);
        int gridViewSpacing = getResources().getDimensionPixelSize(R.dimen.grip_view_spacing);

        WindowManager wm = (WindowManager) getContext().getSystemService(Context.WINDOW_SERVICE);
        Display display = wm.getDefaultDisplay();

        int numColumns = (display.getWidth() - gridViewSpacing) / (gridViewEntrySize + gridViewSpacing);

        gridview.setNumColumns(numColumns);*/
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        refreshGridView();
    }

    @Override
    public void onResume() {
        super.onResume();
        refreshGridView();
    }

    public static boolean isTablet(Context context) {
        return (context.getResources().getConfiguration().screenLayout
                & Configuration.SCREENLAYOUT_SIZE_MASK)
                >= Configuration.SCREENLAYOUT_SIZE_LARGE;
    }

    public static boolean isLandscape(Context context) {
        boolean isLandscapeBoolean = false;
        if (context.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE)
            isLandscapeBoolean = true;
        return isLandscapeBoolean;
    }

}
