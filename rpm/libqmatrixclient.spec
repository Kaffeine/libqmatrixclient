Name:     libqmatrixclient-qt5
Summary:  Matrix Qt library
Version:  0.4.0
Release:  1
Group:    Development/Libraries
License:  LGPL2.1
URL:      https://github.com/Kaffeine/libqmatrixclient
Source0:  %{name}-%{version}.tar.xz
Requires: qt5-qtcore
Requires: qt5-qtnetwork
Requires: qt5-qtgui
BuildRequires: pkgconfig(Qt5Core)
BuildRequires: pkgconfig(Qt5Network)
BuildRequires: pkgconfig(Qt5Gui)
BuildRequires: cmake >= 3.1
BuildRequires: opt-gcc

%description
%{summary}.

%package devel
Summary:    Development files for Matrix Qt library
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}
%description devel
%{summary}.

%package example
Summary:    An example application for Matrix Qt library
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}
%description example
%{summary}.


%prep
%setup -q

%build
%define cmake_build %__cmake --build .
%define cmake_install DESTDIR=%{?buildroot} %__cmake --build . --target install


%cmake \
    -DCMAKE_CXX_COMPILER=/opt/gcc/bin/g++ \
    -DCMAKE_SHARED_LINKER_FLAGS="-L/opt/gcc/lib -static-libstdc++" \
    -DCMAKE_INSTALL_INCLUDEDIR=%{_includedir}/libqmatrixclient-qt5

%cmake_build

%install
rm -rf %{buildroot}
%cmake_install

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%{_libdir}/libQMatrixClient.so.0
%{_libdir}/libQMatrixClient.so.0.4.0

%files devel
%defattr(-,root,root,-)
%{_includedir}/libqmatrixclient-qt5
%{_libdir}/libQMatrixClient.so
%{_libdir}/pkgconfig/QMatrixClient.pc
%{_libdir}/cmake/QMatrixClient

%files example
%defattr(-,root,root,-)
%{_bindir}/*
