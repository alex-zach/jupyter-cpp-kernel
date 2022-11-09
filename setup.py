from setuptools import setup

setup(name='jupyter_cpp_kernel',
      version='0.0.1',
      description='Minimalistic C++ kernel for Jupyter',
      author='Ian Hornik, Alexander Zach',
      author_email='ian.hornik@tuwien.ac.at, alexander.zach@tuwien.ac.at',
      license='MIT',
      classifiers=[
          'License :: OSI Approved :: MIT License',
      ],
      url='https://github.com/alex-zach/jupyter-cpp-kernel/',
      download_url='https://github.com/alex-zach/jupyter-cpp-kernel/tarball/0.0.1',
      packages=['jupyter_cpp_kernel'],
      scripts=['jupyter_cpp_kernel/install_cpp_kernel'],
      keywords=['jupyter', 'notebook', 'kernel', 'C++'],
      include_package_data=True
      )
