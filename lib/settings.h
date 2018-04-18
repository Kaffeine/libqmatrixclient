/******************************************************************************
 * Copyright (C) 2016 Kitsune Ral <kitsune-ral@users.sf.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once

#include <QtCore/QSettings>
#include <QtCore/QVector>
#include <QtCore/QUrl>

class QVariant;

namespace QMatrixClient
{
    class Settings: public QSettings
    {
            Q_OBJECT
        public:
            /**
             * Use this function before creating any Settings objects in order
             * to setup a read-only location where configuration has previously
             * been stored. This will provide an additional fallback in case of
             * renaming the organisation/application.
             */
            static void setLegacyNames(const QString& organizationName,
                                       const QString& applicationName = {});

#if defined(_MSC_VER) && _MSC_VER < 1900
            // VS 2013 (and probably older) aren't friends with 'using' statements
            // that involve private constructors
            explicit Settings(QObject* parent = 0) : QSettings(parent) { }
#else
            using QSettings::QSettings;
#endif

            Q_INVOKABLE void setValue(const QString &key,
                                      const QVariant &value);
            Q_INVOKABLE QVariant value(const QString &key,
                                       const QVariant &defaultValue = {}) const;
            Q_INVOKABLE bool contains(const QString& key) const;
            Q_INVOKABLE QStringList childGroups() const;

        private:
            static QString legacyOrganizationName;
            static QString legacyApplicationName;

        protected:
            const QSettings legacySettings { legacyOrganizationName,
                                             legacyApplicationName };
    };

    class SettingsGroup: public Settings
    {
        public:
            template <typename... ArgTs>
            explicit SettingsGroup(const QString& path, ArgTs... qsettingsArgs)
                : Settings(qsettingsArgs...)
                , groupPath(path)
            { }

            Q_INVOKABLE bool contains(const QString& key) const;
            Q_INVOKABLE QVariant value(const QString &key,
                                       const QVariant &defaultValue = {}) const;
            Q_INVOKABLE QString group() const;
            Q_INVOKABLE QStringList childGroups() const;
            Q_INVOKABLE void setValue(const QString &key,
                                      const QVariant &value);

            Q_INVOKABLE void remove(const QString& key);

        private:
            QString groupPath;
    };

    class AccountSettings: public SettingsGroup
    {
            Q_OBJECT
            Q_PROPERTY(QString userId READ userId CONSTANT)
            Q_PROPERTY(QString deviceId READ deviceId WRITE setDeviceId)
            Q_PROPERTY(QString deviceName READ deviceName WRITE setDeviceName)
            Q_PROPERTY(QUrl homeserver READ homeserver WRITE setHomeserver)
            Q_PROPERTY(bool keepLoggedIn READ keepLoggedIn WRITE setKeepLoggedIn)
            Q_PROPERTY(QString accessToken READ accessToken WRITE setAccessToken)
        public:
            template <typename... ArgTs>
            explicit AccountSettings(const QString& accountId, ArgTs... qsettingsArgs)
                : SettingsGroup("Accounts/" + accountId, qsettingsArgs...)
            { }

            QString userId() const;

            QString deviceId() const;
            void setDeviceId(const QString& deviceId);

            QString deviceName() const;
            void setDeviceName(const QString& deviceName);

            QUrl homeserver() const;
            void setHomeserver(const QUrl& url);

            bool keepLoggedIn() const;
            void setKeepLoggedIn(bool newSetting);

            QString accessToken() const;
            void setAccessToken(const QString& accessToken);
            Q_INVOKABLE void clearAccessToken();
    };
}  // namespace QMatrixClient
