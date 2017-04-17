/*
 * ukf.h
 *
 *  Created on: Apr 6, 2017
 *  Author: ramiz
 *  Description: Header file which contains all the functions for UKF
 */

#ifndef UKF_H_
#define UKF_H_

#include <vector>
#include "Eigen/Dense"

using Eigen::VectorXd;
using Eigen::MatrixXd;

class UKF {
public:
  /**
   * Constructor
   */
  UKF();

  /**
   * Destructor
   */
  virtual ~UKF();

  /**
   * Init Initializes Unscented Kalman filter
   */
  void Init();

  /**
   * Following functions define structure of UKF
   * and I will add code to each of them incrementally
   */
  void GenerateSigmaPoints(MatrixXd* Xsig_out);
  void AugmentedSigmaPoints(MatrixXd* Xsig_out);
  void SigmaPointPrediction(MatrixXd* Xsig_out);
  void PredictMeanAndCovariance(VectorXd* x_pred, MatrixXd* P_pred);
  void PredictRadarMeasurement(VectorXd* z_out, MatrixXd* S_out);
  void UpdateState(VectorXd* x_out, MatrixXd* P_out);

private:
  /**
   * Predicts a single sigma point based on augmented sigma point
   * provided
   * @param x, augmented 7D sigma point
   */
  VectorXd PredictSingleSigmaPoint(const VectorXd & x_aug, double delta_t);
  /**
   * Normalize an angle between -PI and PI
   * @param angle to be normalized
   */
  double NormalizeAngle(double angle);
};



#endif /* UKF_H_ */
