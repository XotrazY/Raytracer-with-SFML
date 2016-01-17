# -*- coding: utf-8 -*-
# Tristan Benoit

import sys
sys.path.append("Test//")

from Vecteur import *
from Couleur import *
from Scene import *

from Test1 import S

import time

D = time.time()

S.Produire_Image_Camera(0)

F = time.time()

S.Sauvegarder_Image_Camera(0,"Image_Test_1")

print("Temps de calcul :", F-D)