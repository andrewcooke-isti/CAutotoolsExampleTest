#!/bin/bash

rm -fr env
virtualenv env
source env/bin/activate
pip install docutils
pip install robotframework
