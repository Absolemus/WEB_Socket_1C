/*
 *  Modern Native AddIn
 *  Copyright (C) 2018  Infactum
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <stdexcept>
#include <thread>

#include "WebSocketAddIn.h"

std::string WebSocketAddIn::extensionName() {
    return "WebSocket";
}

WebSocketAddIn::WebSocketAddIn() {
    addMethods();
    addProperties();
}

void WebSocketAddIn::addMethods() {

    AddMethod(L"Run", L"Запустить", this, &WebSocketAddIn::run);

}

void WebSocketAddIn::addProperties() {

    AddProperty(L"Version", L"ВерсияКомпоненты", [&]() {
        auto s = std::string(Version);
        return std::make_shared<variant_t>(std::move(s));
    });

    host = std::make_shared<variant_t>(std::string("localhost"));
    AddProperty(L"host", L"Хост", host);

    port = std::make_shared<variant_t>(8080);
    AddProperty(L"port", L"Порт", port);

    path = std::make_shared<variant_t>(std::string("/"));
    AddProperty(L"path", L"Путь", path);

}

variant_t WebSocketAddIn::run() {

}

