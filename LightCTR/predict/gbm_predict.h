//
//  gbm_predict.h
//  LightCTR
//
//  Created by SongKuangshi on 2017/9/26.
//  Copyright © 2017年 SongKuangshi. All rights reserved.
//

#ifndef gbm_predict_h
#define gbm_predict_h

#include <stdio.h>
#include "../gbm_algo_abst.h"
#include <cmath>
#include "../util/evaluator.h"

class GBM_Predict {
public:
    GBM_Predict(GBM_Algo_Abst* p, string _testDataPath, bool with_valid_label) {
        this->gbm = p;
        loadDataRow(_testDataPath, with_valid_label);
    }
    ~GBM_Predict() {
        
    }
    void Predict(string);
    void loadDataRow(string, bool);
    
    inline double activFunc(double wx) {
        if(wx < -30){
            return 1e-12;
        } else if(wx > 30){
            return 1.0 - 1e-12;
        }
        return 1.0 / (1.0 + exp(-wx));
    }
private:
    GBM_Algo_Abst* gbm;
    size_t test_dataRow_cnt;
    vector<map<size_t, double> > test_dataSet;
    vector<int> test_label;
};

#endif /* gbm_predict_h */
