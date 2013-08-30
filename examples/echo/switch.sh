#!/bin/bash

CLICK_DIR="/Users/mvhaen/Documents/Work/Courses/Telecommunicatiesystemen/click-2.0.1/elements"

CALL_DIR=$PWD

cd $CLICK_DIR/
unlink local
ln -s $CALL_DIR/$1/elements local
touch $CALL_DIR/$1/elements/*
cd $CALL_DIR/

