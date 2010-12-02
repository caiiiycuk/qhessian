SOURCES_DIRS = \
../rought_3_x \ 
source

defineReplace(sources) {
	out = 

	for(file, SOURCES_DIRS) {
		entries = $$files($$file/$$ARGS)
		for(entry, entries) {
			out += $$entry 
		}
	}

	return($$out)
}

DESTDIR = bin

CONFIG += qt debug
QT -= gui
QT += network

SOURCES += $$sources(*.cpp)
HEADERS += $$sources(*.h) 