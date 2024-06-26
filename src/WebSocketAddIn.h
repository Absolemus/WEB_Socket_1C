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

#ifndef SAMPLEADDIN_H
#define SAMPLEADDIN_H

#include "Component.h"

class WebSocketAddIn final : public Component {
public:
    const char *Version = u8"1.0.0";
    WebSocketAddIn();
private:
    std::string extensionName() override;
    std::shared_ptr<variant_t> host;
    std::shared_ptr<variant_t> port;
    std::shared_ptr<variant_t> path;
    void addMethods();
    void addProperties();
    variant_t run();
};

#endif //SAMPLEADDIN_H
