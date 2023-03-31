SHELL := /bin/bash
arch=`dpkg --print-architecture`
export version=1.0.0
build:
	# 编译
	mkdir building -p
	
	cd building/ && qmake ..
	cd building/ && make -j$(nproc)

clean:
	rm -rf building
	rm -rf build
	rm -rf /tmp/timer-building

package:
	make build -j$(nproc)
	#export arch=`arch`
	cp building/Timer deb/usr/bin/timer-dtk
	mkdir -p /tmp/timer-building
	cp deb/* /tmp/timer-building -r
	sed -i "s/@@version@@/${version}/g" /tmp/timer-building/DEBIAN/control #> /tmp/timer-building/DEBIAN/control
	sed -i "s/@@arch@@/${arch}/g" /tmp/timer-building/DEBIAN/control #> /tmp/timer-building/DEBIAN/control
	dpkg -b /tmp/timer-building spark.gitee.timer_${version}_${arch}.deb
	rm -rf /tmp/timer-building
