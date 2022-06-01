/*
** EPITECH PROJECT, 2022
** server
** File description:
** subscribe
*/

#include "server.h"

void subscribe_server(int i)
{
    team_t *team = NULL;
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    CHECK(!C_CMD[1], E_SYNTAX);
    team = get_team(C_CMD[1]);
    CHECK(!team, E_TEAM);
    CHECK(is_subscribed(i, team->uuid), E_EXIST);
    server_event_user_subscribed(team->uuid, C_UUID);
    add_subscription(i, team->uuid);
    SEND(i, M_SUBSCRI_C);
}

void subscribed_server(int i)
{
    user_t *user = NULL;
    subscription_t *subscription = NULL;
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    user = get_user(C_UUID);
    CHECK(user == NULL, E_KO);
    subscription = user->subscriptions;
    while (subscription) {
        SEND(i, M_SUBSCRI_L, subscription->uuid);
        subscription = subscription->next;
        handle_client(i);
    }
}

void unsubscribe_server(int i)
{
    team_t *team = NULL;
    CHECK(!C_CONNECTED, E_UNAUTHORIZED);
    CHECK(!C_CMD[1], E_SYNTAX);
    team = get_team(C_CMD[1]);
    CHECK(!team, E_TEAM);
    CHECK(!is_subscribed(i, team->uuid), E_KO);
    remove_subscription(i, team->uuid);
    SEND(i, M_OK);
}