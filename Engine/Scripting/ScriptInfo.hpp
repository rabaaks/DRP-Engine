#pragma once

namespace Engine
{
    class Script;

    struct ScriptInfo
    {
        Script* (*create)();
        void (*destroy)(Script*);
    };
}