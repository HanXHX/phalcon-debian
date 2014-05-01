#!/bin/sh

./clean.sh

if [ -f ./source_vars ]
then
	. ./source_vars
else
	echo "Are you in good folder?"
	exit 1
fi

echo "1) Downloading from upstream (version: $VERSION)"
wget $URL_SOURCE -O $ARCHIVE  

echo "2) Ungzip"
tar xfz $ARCHIVE $DEST_FOLDER
mv cphalcon* phalcon

echo "3) Build package"
dpkg-buildpackage -b
