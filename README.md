# PaintBrush
implementation of Implementation of Aaron Hertzmann's paper "Painterly Rendering with Curved Brush Strokes of Multiple Sizes".


### To test the code
Install g++ opencv4, and cmake
ensure cmd command ```pkg-config opencv4 --cflags --libs``` return all opencv4 dependencies
for example:
```
$pkg-config opencv4 --cflags --libs
-I/usr/local/Cellar/opencv/4.5.1_3/include/opencv4 -L/usr/local/Cellar/opencv/4.5.1_3/lib -lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_highgui -lopencv_datasets -lopencv_text -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_dnn -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core
```

After make sure opencv is installed, run
```
make
./finalProject.o [path to source video]         # default in opencv DIVX encoding
./finalProject.o [path to source video] MJPEG   # use MJPEG encoding instead
```
the window will show the processed frame, and f.avi will be created in the current directory.

### To Use the Library
There are two class in this code. Para.hpp is the class to store all parameters, and Paint.hpp is to implement the painting algorithm.
Include Para.hpp and Paint.hpp, and call paint() function in Paint.hpp for each frame you would like to process.
Check finalProject.cpp for an example.


![avatar](Screen Shot 2021-06-28 at 11.26.53 PM.png<img width="848" alt="Screen Shot 2021-06-28 at 11 26 53 PM" src="https://user-images.githubusercontent.com/24727472/123725475-b102c000-d8c0-11eb-8733-efa607cbf101.png">
)
