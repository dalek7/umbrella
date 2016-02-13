% last modified on 10/7/2013
% for creating 3D primitives used for UIST2013 demo
% http://uist.acm.org/uist2013/
% Seung-Chan Kim in the airplane
% based on http://www.aleph.se/Nada/Ray/matlabobj.html

close all; clear; clc;

% [u,v]=meshgrid(-6:0.5:6,-6:0.5:6);
% x=u; y=v; z=u.^2+v.^2;
% mesh(x,y,z)
% saveobjmesh('parab.obj',x,y,z)


m =8;

if m==1,
    [x,y]=meshgrid(-1:0.05:1,-1:0.05:1);
    z =0.5*exp(-(x.^2)/0.1);
    saveobjmesh('primitives_gauss_1d.obj',x,z,y);
    mesh(x,y,z);
    axis equal;
    view(-17,20);
    
elseif m==2,
%   [x,y]=meshgrid(-1:0.05:1,-1:0.05:1);
    r=linspace(0,2,20);
    theta=linspace(0,2*pi,40);
    [r,theta]=meshgrid(r,theta);

    x=r.*cos(theta);
    y=r.*sin(theta);
    
    z = 1*exp(-(x.^2+y.^2)/0.5);
    saveobjmesh('primitives_gauss_2d.obj',x,z,y);
    mesh(x,y,z);
    axis equal;
    view(-17,20);

    
% 

elseif m==3,
%     [x,y]=meshgrid(-10:0.5:10,-10:0.5:10);
r=linspace(0,2,20);
    theta=linspace(0,2*pi,40);
    [r,theta]=meshgrid(r,theta);

    x=r.*cos(theta);
    y=r.*sin(theta);
    
    z = -1* (x.^2 + y.^2);
    saveobjmesh('primitives_parabola_2d.obj',x,z,y);
    mesh(x,y,z);
    axis equal;
    view(-17,20);
%http://msemac.redwoods.edu/~darnold/math50c/matlab/coordcyl/index.xhtml   

elseif m==5,
    r=linspace(0,2,20);
    theta=linspace(0,2*pi,40);
    [r,theta]=meshgrid(r,theta);

    x=r.*cos(theta);
    y=r.*sin(theta);
    z=-r;
    saveobjmesh('primitives_cone_2d.obj',x,z,y);
    mesh(x,y,z);
    axis equal;
    
%http://www.mathworks.com/matlabcentral/newsreader/view_thread/126008    
elseif m==6,
    r=1; % small radius of the donut
    d=2; % distance of small circle to the center (or radius of rotation
    %of small circle)

    phi=(0:pi/16:2*pi)'; % points of small circle
    alpha=(0:pi/32:2*pi)'; % points of big circle

    X2=[d+r*cos(phi) r*sin(phi)]; % small circle
    Z=X2(:,2)';Z=Z(ones(1,length(alpha)),:);
    X=cos(alpha)*X2(:,1)';
    Y=sin(alpha)*X2(:,1)';
    surf(X,Y,Z)
    axis equal;

    view(-17,20);
    
    saveobjmesh('primitives_doughnut.obj',X,Z,Y);
    
%http://www.semifluid.com/2012/12/05/2d-and-3d-perlin-noise-in-matlab/    
elseif m==7,
    [x,y]=meshgrid(-1:0.05:1,-1:0.05:1);
    z = perlinNoise2d(41);
    surf(x,y,z);
     view(-17,20);
    saveobjmesh('primitives_perlinnoise_2d.obj',x,z,y);

    
elseif m ==8,
    R = 1;
    [x,y,z] = ellipsoid(0,0,0,R,R,R);
    surf(x,y,z);
    
    axis equal;
    
    saveobjmesh('primitives_sphere.obj',x,z,y);    

    %Radial sine wave
elseif m==10,
%     [x,y]=meshgrid(-10:0.5:10,-10:0.5:10);
    r=linspace(0,2,20);
    theta=linspace(0,2*pi,40);
    [r,theta]=meshgrid(r,theta);

    x=r.*cos(theta);
    y=r.*sin(theta);
    
    z = -0.5*sin(0.3* 2*pi * (x.^2 +y.^2 ) / 1 );
    saveobjmesh('primitives_radial_sine_2d.obj',x,z,y);
    mesh(x,y,z);
    axis equal;
end



    