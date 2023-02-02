/**
 * @file option.cpp
 * @brief Implémentation de la classe abstraite Option et de ses classes concrètes Put et Call
 */

#include "option.h"  // Pour la déclaration de la classe Option

/**
 * @brief Constructeur de la classe Option
 * @param K Strike de l'option
 * @param T Temps terminal de l'option
 * @param L Valeur terminal de l'option
 * @param r Taux d'intérêt du marché
 * @param sigma Volatilité de l'actif
 */
Option::Option(double K, double T, double L, double r, double sigma) : K_(K), T_(T), L_(L), r_(r), sigma_(sigma) {}

/**
 * @brief Constructeur de la classe Put
 * @param K Strike de l'option
 * @param T Temps terminal de l'option
 * @param L Valeur terminal de l'option    
 * @param r Taux d'intérêt du marché
 * @param sigma Volatilité de l'actif
 */
Put::Put(double K, double T, double L, double r, double sigma) : Option(K, T, L, r, sigma) {}

/**
 * @brief Implémentation de la méthode virtuelle pure payoff
 * @param S Valeur de l'actif en temps t
 * @param t Valeur du temps t
 * @return Payoff de l'option put pour la valeur de l'actif S au temps t
 */
double Put::payoff(double S, double t) const
{
    if (S == 0)
        return K_ * std::exp(-r_ * (T_ - t));
    else if (S == L_)
        return 0;
    else if (t == T_)
        return std::max(0.0, K_ - S);
    else
        return 0;
}

/**
 * @brief Constructeur de la classe Call
 * @param K Strike de l'option
 * @param T Temps terminal de l'option
 * @param L Valeur terminal de l'option
 * @param r Taux d'intérêt du marché
 * @param sigma Volatilité de l'actif
 */
Call::Call(double K, double T, double L, double r, double sigma) : Option(K, T, L, r, sigma) {}

/**
 * @brief Implémentation de la méthode virtuelle pure payoff
 * @param S Valeur de l'actif en temps t
 * @param t Valeur du temps t
 * @return Payoff de l'option call pour la valeur de l'actif S au temps t
 */
double Call::payoff(double S, double t) const 
{
    if (S == 0)
        return 0;
    else if (S == L_)
        return K_ * std::exp(-r_ * (t - T_));
    else if (t == T_)
        return std::max(0.0, S - K_);
    else
        return 0;
}
