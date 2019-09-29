#include <iostream>
#include <exception>

//Includes para OpenCV, Descomentar según los módulo utilizados.
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/calib3d/calib3d.hpp>

const cv::String keys =
  "{help h usage ? |      | print this message   }"
  "{path           |.     | path to file         }"
  "{fps            | -1.0 | fps for output video }"
  "{N count        |100   | count of objects     }"
  "{ts timestamp   |      | use time stamp       }"
  "{@image1        |      | image1 for compare   }"
  "{@image2        |<none>| image2 for compare   }"
  "{@repeat        |1     | number               }"
;

















int main (int argc, char* const* argv) {
  int retCode=EXIT_SUCCESS;

  try {
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Application name v1.0");

    if (parser.has("help")) {
      parser.printMessage();
      return 0;
    }

    int N = parser.get<int>("N");
    double fps = parser.get<double>("fps");
    cv::String path = parser.get<cv::String>("path");
    bool use_time_stamp = parser.has("timestamp");
    cv::String img1 = parser.get<cv::String>(0);
    cv::String img2 = parser.get<cv::String>(1);
    int repeat = parser.get<int>(2);

    if (!parser.check()) {
      parser.printErrors();
      return 0;
    }








    // Carga de una imagen seleccionada por el usuario (color o monocroma)
    cv::Mat img = cv::imread(img_name, cv::IMREAD_ANYCOLOR);

    if (img.empty()) {
       std::cerr << "Error: no he podido abrir el fichero '" << img_name << "'." << std::endl;
       return EXIT_FAILURE;
    }

    //Creo la ventana grafica para visualizar la imagen.
    //El nombre de la ventana sirve como 'handle' para gestionarla despues.
    cv::namedWindow("IMAGEN ORIGINAL");

    //Visualizo la imagen cargada en la ventana.
    cv::imshow("IMAGEN ORIGINAL", img);



    // Normalizamos la imagen que se carga
    cv::Mat img_procesada;
    img.convertTo(img_procesada, CV_32F, 1.0 / 255, 0);




    cv::Mat img_procesada;
    cv::namedWindow("IMAGEN PROCESADA");
    cv::imshow("IMAGEN PROCESADA", img_procesada);








  }

  catch (std::exception& e) {
    std::cerr << "Capturada excepcion: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }

  return retCode;
}
