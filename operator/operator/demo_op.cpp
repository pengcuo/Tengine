/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * AS IS BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * Copyright (c) 2018, Open AI Lab
 * Author: haitao@openailab.com
 */
#include "operator/demo_op.hpp"

namespace TEngine {

/* 
   DemoOps demos to permute a 2d matrix and 
   then expanding one column to summerize each row of the permuted matrix 
*/

bool DemoOp::InferShape(const std::vector<TShape>& ishape, std::vector<TShape>& oshape, int layout)
{
    int h=ishape[0].Shape(0);
    int w=ishape[0].Shape(1);
    std::vector<int> dims;

    dims.push_back(w);
    dims.push_back(h+1);

    oshape[0].SetDim(dims);
    oshape[0].SetDataLayout(layout); 

    return true;
}


void DemoOp::SetSchema(void)
{
    Input({"input:float32/int8"})
        .Output({"output:float32/int8"})
        .SetDoc(R"DOC(Demo Operator: a demo operator to show how to define and run a operator)DOC");
}

}    // namespace TEngine
