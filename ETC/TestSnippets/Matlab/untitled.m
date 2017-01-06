clc; clear; close all;
A = load('out_samplertest.txt');
x = ones(size(A));


figure;
buf = sprintf('Gaussian random with a mean and standard deviation. (%d samples, m=0, stdev=1)', size(A, 1));
subplot(2,1,1);
plot( A,x, '.');
title(buf);

subplot(2,1,2);
histogram(A);
title('histogram');