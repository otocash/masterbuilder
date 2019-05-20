#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/OTOCASH.ico

convert ../../src/qt/res/icons/OTOCASH-16.png ../../src/qt/res/icons/OTOCASH-32.png ../../src/qt/res/icons/OTOCASH-48.png ${ICON_DST}
