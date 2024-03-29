#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>

using namespace dlib;
using namespace std;

int main()
{
    try
    {
        cv::VideoCapture cap("http://192.168.15.4:8080/video");
        if (!cap.isOpened())
        {
            cerr << "Problema ao conectar" << endl;
            return 1;
        }

        image_window win;
        frontal_face_detector detector = get_frontal_face_detector();
        shape_predictor pose_model;
        deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;

        
        while(!win.is_closed())
        {
            cv::Mat temp;
            if (!cap.read(temp))
            {
                break;
            }
            cv_image<bgr_pixel> cimg(temp);

             
            std::vector<rectangle> faces = detector(cimg);
            
            std::vector<full_object_detection> shapes;
            for (unsigned long i = 0; i < faces.size(); ++i)
                shapes.push_back(pose_model(cimg, faces[i]));

            
            win.clear_overlay();
            win.set_image(cimg);
            win.add_overlay(render_face_detections(shapes));
        }
    }

    catch(exception& e)
    {
        cout << e.what() << endl;
    }
}