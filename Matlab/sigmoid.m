function a = sigmoid(x, slope, center)
% Seung-Chan Kim
% October 11, 2011
% Disney Research Pittsburgh
if nargin==1,
   slope = 1;
   center = 0;
end
    
a = 1.0 ./ (1 + exp(slope*(-x + center)));