CPP = g++ -std=c++11
INC = -I../cryphutil -I../fontutil -I../glslutil -I../mvcutil
C_FLAGS = -fPIC -g -c -DGL_GLEXT_PROTOTYPES $(INC)

LINK = g++ -fPIC -g
LOCAL_UTIL_LIBRARIES = ../lib/libcryph.so ../lib/libfont.so ../lib/libglsl.so ../lib/libmvc.so
GL_LIB_LOC = -L/usr/lib/nvidia-375
GL_LIBRARIES = $(GL_LIB_LOC) -lglfw -lGLU -lGL

OBJS = main.o Table.o Wall.o ModelView_Additions.o RectangularPrism.o Cylinder.o Bed.o Floor.o Fireplace.o

main: $(OBJS) $(LOCAL_UTIL_LIBRARIES)
	$(LINK) -o main $(OBJS) $(LOCAL_UTIL_LIBRARIES) $(GL_LIBRARIES)

../lib/libcryph.so: ../cryphutil/AffVector.h ../cryphutil/AffVector.c++ ../cryphutil/AffPoint.h ../cryphutil/AffPoint.c++
	(cd ../cryphutil; make)

../lib/libfont.so: ../fontutil/CFont.h ../fontutil/CFont.c++ ../fontutil/CGLString.h ../fontutil/CGLString.c++
	(cd ../fontutil; make)

../lib/libglsl.so: ../glslutil/ShaderIF.h ../glslutil/ShaderIF.c++
	(cd ../glslutil; make)

../lib/libmvc.so: ../mvcutil/Controller.h ../mvcutil/Controller.c++ ../mvcutil/ModelView.h ../mvcutil/ModelView.c++
	(cd ../mvcutil; make)

main.o: main.c++
	$(CPP) $(C_FLAGS) main.c++

Bed.o: Bed.h Bed.c++
	$(CPP) $(C_FLAGS) Bed.c++

Table.o: Table.h Table.c++
	$(CPP) $(C_FLAGS) Table.c++

Floor.o: Floor.h Floor.c++
	$(CPP) $(C_FLAGS) Floor.c++

Wall.o: Wall.h Wall.c++
	$(CPP) $(C_FLAGS) Wall.c++

Fireplace.o: Fireplace.h Fireplace.c++
	$(CPP) $(C_FLAGS) Fireplace.c++

Cylinder.o: Cylinder.h Cylinder.c++
	$(CPP) $(C_FLAGS) Cylinder.c++

RectangularPrism.o: RectangularPrism.h RectangularPrism.c++
	$(CPP) $(C_FLAGS) RectangularPrism.c++

ModelView_Additions.o: ModelView_Additions.c++
	$(CPP) $(C_FLAGS) ModelView_Additions.c++
