rm vsgame
g++ -Wall \
vilsoc/vilsoc.cpp \
vilsoc/initializer.cpp \
vilsoc/zone.cpp \
vilsoc/villager.cpp \
vilsoc/engine.cpp \
vilsoc/world.cpp \
main.cpp \
-lsfml-graphics -lsfml-window -lsfml-system -o vsgame
