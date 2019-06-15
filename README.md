# Facedet
Reconhecimento facial em C++
Programa para reconhecimento facial com camera ip de telefone (feito devido usar um desktop e ser a unica camera disponivel)
Comando para executar - g++ -std=c++11 -O3 -I.. localdlib/dlib/all/source.cpp -lpthread -lX11 facedet.cpp -ljpeg -lpng -DDLIB_JPEG_SUPPORT -DDLIB_PNG_SUPPORT `pkg-config --cflags --libs opencv` -o FaceDet
Link para .dat de modelo http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2
