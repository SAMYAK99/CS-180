# import the required packages
import os
import sys
import numpy as np
import pandas as pd
import sklearn
from sklearn.model_selection import train_test_split
from scipy.io import loadmat


# importing the models from the pyod
import pyod
from pyod.models.pca import PCA
from pyod.models.mcd import MCD
from pyod.models.ocsvm import OCSVM
from pyod.models.lof import LOF
from pyod.models.cblof import CBLOF
from pyod.models.knn import KNN
from pyod.models.hbos import HBOS
from pyod.models.abod import ABOD
from pyod.models.iforest import IForest
from pyod.models.feature_bagging import FeatureBagging

# performance metrics packages

from pyod.utils.utility import standardizer
from pyod.utils.utility import precision_n_scores
from sklearn.metrics import roc_auc_score


# Define the datafile and read X and y

mat_file_list = ['arrhythmia.mat',
                 ' cardio.mat',
                 'glass.mat',
                 'ioneshphere.mat',
                 'letter.mat',
                 'lympho.mat',
                 'mnist.mat',
                 'musk.mat',
                 'optdigits.mat',
                 'pendigits.mat',
                 'pima.mat',
                 'satellite.mat',
                 'shuttle.mat',
                 'vertebral.mat',
                 'vowels.mat',
                 'wbc.mat']
                 
            
df_columns = ['Data', ' # Samples' , '# Dimensions' , 'Outliers Perc' , 'ABOD','CBLOF','FB','HBOS' , 'IForest', 'KNN' , 'LOF' , 'MCD','OCSVM','PCA']

              
roc_df = pd.DataFrame
                 
                 
                 
                 
                 
                 
            


















