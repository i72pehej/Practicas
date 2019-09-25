/*!
  Esto es un esqueleto de programa para usar en las prácticas
  de Visión Artificial.

  Se supone que se utilizará OpenCV.

  Para compilar, puedes ejecutar:
    g++ -Wall -o esqueleto esqueleto.cc `pkg-config opencv --cflags --libs`

*/

#include <iostream>
#include <exception>

//Includes para OpenCV, Descomentar según los módulo utilizados.
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/calib3d/calib3d.hpp>

const cv::String keys =
  // "{help h usage ? |      | print this message   }"
  // "{path           |.     | path to file         }"
  // "{fps            | -1.0 | fps for output video }"
  // "{N count        |100   | count of objects     }"
  // "{ts timestamp   |      | use time stamp       }"
  "{@image1        |<none>| image to modify}"
  // "{@image2        |<none>| image2 for compare   }"
  // "{@repeat        |1     | number               }"
  ;



////////////////////////////////////////////////////////////////////////////////

// Gestión del mouse
void on_mouse(int event, int x, int y, int flags, void *userdata) {
  switch (event) {
    case cv::EVENT_LBUTTONDOWN:
      static_cast<int*>(userdata)[0] = x;
      static_cast<int*>(userdata)[1] = y;

    break;

    case cv::EVENT_MOUSEMOVE:
    break;
  }








}

////////////////////////////////////////////////////////////////////////////////

int main (int argc, char* const* argv) {
  int retCode = EXIT_SUCCESS;

  // Puntos para el rectangulo
  cv::Point p1(0, 0);
  cv::Point p2(0, 0);

  // Tipo rectangulo directamente, para pasarlo como argumento a la función rectangle().
  cv::Rect rectangulo;
  // ?¿?¿?¿??¿¿???¿?¿?¿
  rectangulo = cv::Rect(x, y, ancho, alto);


  try {
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Application name v1.0.0");
    cv::String img_name = parser.get<cv::String>(0);

    if (!parser.check()) {
      parser.printErrors();
      return 0;
    }

    /*Ahora toca que tu rellenes con lo que hay que hacer ...*/







    //Carga la imagen desde archivo.
    //En funcion de como se compilo opencv podra
    //cargar mas o menos formatos graficos.
    //Lee la documentacion de imread para ver mas detalles.
    cv::Mat img = cv::imread(img_name, cv::IMREAD_COLOR);

    if (img.empty()) {
      std::cerr << "Error: no he podido abrir el fichero '" << img_name << "'." << std::endl;
      return EXIT_FAILURE;
    }

    //Creo la ventana grafica para viscv::polylines (InputOutputArray img, InputArrayOfArrays pts, bool isClosed, const Scalar &color, int thickness=1, int lineType=LINE_8, int shift=0)ualizar la imagen.
    //El nombre de la ventana sirve como 'handle' para gestionarla despues.
    //Lee la documentacon de namedWindow para mas detalles.
    cv::namedWindow("IMG");

    //Visualizo la imagen cargada en la ventana.
    cv::imshow("IMG", img);

    //Conectamos a la ventana un callback para gestionar el raton.
    int coords[2] = {-1, -1};
    cv::setMouseCallback("IMG", on_mouse, coords);

    //Para que se actualice la interfaz grafica es necesario llamar a
    //waitKey. Además esta función nos permite interactuar con el teclado.
    //Lee la documentacion de waitKey para mas detalles.
    cv::waitKey(0);



    // Dibuja un rectángulo relleno o vacío.
    img = cv.rectangle(img, pt1, pt2, color[, thickness[, lineType[, shift]]]	)

    // // Dibuja líneas para crear el polígono.
    // cv::polylines (InputOutputArray img, InputArrayOfArrays pts, bool isClosed, const Scalar &color, int thickness=1, int lineType=LINE_8, int shift=0)





  }

  catch (std::exception &e) {
    std::cerr << "Capturada excepcion: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }

  return retCode;
}
