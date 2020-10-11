#!/bin/bash

CURDIR=`/bin/pwd`
BASEDIR=$(dirname $0)
ABSPATH=$(readlink -f $0)
ABSDIR=$(dirname $ABSPATH)

echo "CURDIR is $CURDIR"
echo "BASEDIR is $BASEDIR"
echo "ABSPATH is $ABSPATH"
echo "ABSDIR is $ABSDIR"
