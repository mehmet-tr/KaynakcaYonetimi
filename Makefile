all: KaynakcaYonetimi
KaynakcaYonetimi:
	g++ -lsqlite3 -lwxsqlite3-`wx-config --release` `wx-config --cxxflags --libs` -o KaynakcaYonetimi src/main.cpp src/main.h src/kaynakcayonetimi.cpp src/kaynakcayonetimi.h src/eklekitap.cpp src/eklekitap.h src/eklemakale.cpp src/eklemakale.h src/bulisbn.cpp src/bulisbn.h src/buldoi.cpp src/buldoi.h src/ekleliste.cpp src/ekleliste.h src/md5.cpp src/md5.h src/wxlibs.h
install:
	cp -rf KaynakcaYonetimi /usr/local/bin/KaynakcaYonetimi
uninstall:
	rm -rf /usr/local/bin/KaynakcaYonetimi
clean:
	rm -f KaynakcaYonetimi
