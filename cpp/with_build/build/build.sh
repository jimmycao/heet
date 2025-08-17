project_home=$(cd $(dirname $0); pwd)/..

echo ${project_home}
src_path=${project_home}/src

# build
cd ${src_path}
rm -rf build
mkdir build; cd build
cmake ../
make -j8
