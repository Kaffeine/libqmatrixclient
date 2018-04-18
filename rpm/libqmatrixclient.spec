Name:     libqmatrixclient-qt5
Summary:  Matrix Qt library
Version:  0.1.0
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
%cmake \
    -DBUILD_SHARED_LIBS=ON \
    -DCMAKE_INSTALL_INCLUDEDIR=include/libqmatrixclient-qt5

make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%make_install

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%{_libdir}/libQMatrixClient.so.0
%{_libdir}/libQMatrixClient.so.0.1.0

%files devel
%defattr(-,root,root,-)
%{_includedir}/libqmatrixclient-qt5
%{_libdir}/libQMatrixClient.so
%{_libdir}/cmake/QMatrixClient

%files example
%defattr(-,root,root,-)
%{_bindir}/*
